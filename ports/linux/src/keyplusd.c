// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <syslog.h>
#include <signal.h>
#include <pwd.h>

#include "cmdline.h"
#include "debug.h"

int kp_mainloop(int, const char **);

static int m_lockfile_fd = -1;
static struct cmdline_args m_settings;

static int m_uid = -1;
static int m_gid = -1;

void set_target_user(void) {
    struct passwd *pwd;

    // when not running in daemon mod, don't attempt to switch the user
    if (!m_settings.daemonize) {
        m_uid = getuid();
        m_gid = getgid();
        return;
    }

    errno = 0;
    pwd = getpwnam("keyplusd");

    if (pwd == NULL && errno) {
        perror("error looking up keyplusd user");
        exit(EXIT_FAILURE);
    }

    if (pwd == NULL) {
        fprintf(stderr, "error: couldn't find keyplusd user");
        exit(EXIT_FAILURE);
    }
    m_uid = pwd->pw_uid;
    m_gid = pwd->pw_gid;
}

void downgrade_user(void) {
    int rc;

    rc = setgid(m_gid);
    if (rc < 0) {
        perror("error switching to keyplusd group failed");
        exit(EXIT_FAILURE);
    }
    rc = setuid(m_uid);
    if (rc < 0) {
        perror("error switching to keyplusd user");
        exit(EXIT_FAILURE);
    }
}

/// unlock, close and delete the lockfile
static void close_lockfile(void) {
    int rc;

    if (m_lockfile_fd == -1) {
        return;
    }

    KP_ASSERT(m_settings.lockfile != NULL);

    rc = unlink(m_settings.lockfile);

    if (rc < 0) {
        syslog(LOG_WARNING, "failed to remove lockfile: %s", strerror(errno));
    }

    rc = lockf(m_lockfile_fd, F_ULOCK, 0);
    rc = close(m_lockfile_fd);
    KP_CHECK_ERRNO(rc);
    m_lockfile_fd = -1;

    KP_DEBUG_PRINT(1, "released lockfile: %s\n", m_settings.lockfile);
}

static void open_lockfile(void) {
    int rc;

    KP_ASSERT(m_settings.lockfile != NULL);

    // Check for lock file
    rc = open(m_settings.lockfile, O_CREAT | O_EXCL | O_RDWR, 0664);
    if (rc < 0) {
        perror("failed to create lockfile");
        exit(EXIT_FAILURE);
    }
    m_lockfile_fd = rc;

    atexit(close_lockfile);

    rc = chown(m_settings.lockfile, m_uid, m_gid);
    KP_CHECK_ERRNO(rc);

    // try to gain an exclusive lock, don't block
    rc = lockf(m_lockfile_fd, F_TLOCK, 0);

    if (rc < 0) {
        if (errno == EWOULDBLOCK) {
            syslog(LOG_ERR, "couldn't claim lockfile: %s", m_settings.lockfile);
            // print to stderr too so parent tty can see the message
            fprintf(stderr, "couldn't claim lockfile: %s\n", m_settings.lockfile);
            exit(EXIT_FAILURE);
        } else {
            KP_CHECK_ERRNO(rc);
        }
    } else {
        // claimed the lock file, write our PID to that file as string
        char str[32];
        sprintf(str, "%d\n", getpid());
        rc = write(m_lockfile_fd, str, strlen(str));
        if (rc < 0) {
            syslog(LOG_ERR, "writing to lockfile failed: %s\n", m_settings.lockfile);
            fprintf(stderr, "couldn't claim lockfile: %s\n", m_settings.lockfile);
            exit(EXIT_FAILURE);
        }
    }
}

void daemonize(void) {
    int rc;
    pid_t pid;

    // increase our priority
    errno = 0;
    rc = nice(-10);
    if (rc == -1 && !errno) {
        KP_LOG_ERRNO("failed to set priority");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    KP_CHECK_ERRNO(pid);

    // exit parent process so child is orphaned
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    set_target_user(); // set which user we will run as (while we are still root)

    open_lockfile();

    downgrade_user(); // switch to the user we chose above

    // Setup child process
    umask(0);
    const pid_t sid = setsid();
    KP_CHECK_ERRNO(sid);

    rc = chdir("/");
    KP_CHECK_ERRNO(rc);

    // Flush streams and close
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    stdin = fopen("/dev/null", "r");
    stdout = fopen("/dev/null", "w+");
    stderr = fopen("/dev/null", "w+");
}

void signal_handler(int sig) {
    switch (sig) {
        case SIGTERM:
        case SIGINT: {
            int rc;
            struct sigaction sigact;

            syslog(LOG_INFO, "got signal %d: '%s', preparing to shutdown", sig, strsignal(sig));

            // Re-enable the default action, something goes wrong in cleanup
            // we can still be terminated.
            sigact.sa_handler = SIG_DFL;
            sigemptyset(&sigact.sa_mask);
            sigact.sa_flags = 0;
            rc = sigaction(SIGINT, &sigact, NULL);
            rc = sigaction(SIGTERM, &sigact, NULL);
            KP_CHECK_ERRNO(rc);
        } break;
    }
}



int main(int argc, char **argv) {
    int rc;
    char* proc_name = argv[0];

    parse_cmdline_args(&m_settings, argc, argv);

    openlog(proc_name, LOG_PID|LOG_CONS, LOG_DAEMON);

    // setup signal handlers
    {
        struct sigaction sigact;
        sigact.sa_handler = signal_handler;
        sigemptyset(&sigact.sa_mask);
        sigact.sa_flags = 0;

        rc = sigaction(SIGINT, &sigact, NULL);
        rc = sigaction(SIGTERM, &sigact, NULL);
        KP_CHECK_ERRNO(rc);
    }

    if (m_settings.daemonize) {
        KP_DEBUG_PRINT(1, "daemonizing\n");
        daemonize();
    } else {
        open_lockfile();
    }

    KP_LOG_INFO("Starting keyplus daemon");
    {
        int argc = 2;
        const char *argv[2];
        argv[1] = m_settings.config;
        rc = kp_mainloop(argc, argv);
    }

    close_lockfile();

    // under normal use, shouldn't reach this code
    KP_LOG_INFO("Closing keyplus daemon");
    closelog();

    return 0;
}
