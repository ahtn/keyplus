# linux keyplus emulator

`keyplusd` is an emulator that allows you to run keyplus on any keyboard.
It runs as a process on your computer and remaps keyboard and mouse actions
according to your keyplus layout file.

## Install

### Install for Archlinux

Install [`keyplusd-git`](https://aur.archlinux.org/packages/keyplusd-git/) from the AUR.

### Build and install from source

To install run:

```
make
make install
```

NOTE: you may need to reboot before some of the udev rules to take effect.

## Simple usage

To load a configuration file for the daemon to use, run:

```
../../host-software/keyplus-cli program -D your_conf.yaml
```

For an example configuration file see
[`layouts/virtual.yaml`](../../layouts/virtual.yaml).  Then to start the daemon
run:

```
keyplusd
```

NOTE: You will need root privileges to run these commands.

## Enable at boot

To start `keyplusd` when the computer is powered, use the system service:

```
systemctl enable keyplusd
```

## Configuration

TODO

## Key usage statistics

`keyplusd` can track key usage statistics. By default they are saved to
`/var/lib/keyplusd/stats.json`. For security reasons viewing this file requires
root permissions, or the user must be added to the `keyplusd` group.

The file is formated as a json file is formated like:

```json
{
  "devices": [
    {
      "A": 123,
      ...
    },
    ...
    {
    }
  ]
}
```

Where element `i` in the `devices` array contains the key press counts for the
device with `id=i`. The values reflect the keys before they are remapped by the
keyplus emulator. If a keycode is not present, then it has been pressed 0
times.

The names of the keycodes are based of their HID usage
codes . For a list of possible values see
[`src/stats_parser.c`](ports/linux/src/stats_parser.c).

The stats file is periodically updated by `keyplusd`, however, you can run
`keyplusd -r` to force an update immediately.

To disable logging for a device, set `scan_mode.stats` to `false` in the
configuration file.

* TODO: some media keycodes not handled yet

## Debugging

For debugging, it may be more convenient to run `keyplusd` as the current user.
To run `keyplusd` as the current user in the shell:

```
make run
```

For this to work, without root permissions added your user to the `keyplusd`
group and re-login:

```
usermod -a -G keyplusd <useraccount>
```

To change the amount of debug output, change the value of the `DEBUG` flag in
the makefile to a higher value.

The default keymap layout for the `make run` command is `layouts/virtual.yaml`.
You can provide another layout file by running make with the
`TEST_CONFIG_LAYOUT` variable:

```
make run TEST_CONFIG_LAYOUT=./config.yaml
```

## Debugging - run as daemon

```
make run-daemon
```

To see log output from the daemon, use:

```
journalctl -b -f
```

NOTE: since the daemon runs as the `keyplusd` user, make sure the config file
is located where the `keyplusd` user will have read access.

## Debugging - killing the daemon

To kill the daemon run:

```
keyplusd -k
```

If you have built the project in debug mode, you can also use `DEBUG_EXIT_KEY`
to kill the daemon. By default this value is set to `KEY_F1`. This is the value
of the key before it is remapped by keyplus. To disable this feature, set
`DEBUG_EXIT_KEY=0`.
