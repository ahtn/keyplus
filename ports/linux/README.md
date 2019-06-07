# linux keyplus emulator

`keyplusd` is an emulator that allows you to run keyplus on any keyboard.
It runs as a process on your computer and remaps keyboard and mouse actions
according to your keyplus layout file.

## TODO

* TODO: allow the config file to be changed without restarting `keyplusd`
* TODO: document layout configuration

## Setup

Run

```
./setup.sh
```

After running this script you may need to reboot for some of the `udev` rules
to take effect.  To build the daemon, run:

```
make
```

When make finishes the executable will be placed in the `build` directory.

## Install

TODO

## Simple usage

To load a configuration file for the daemon to use, run:

```
../../host-software/keyplus-cli program -D your_conf.yaml
```

For an example configuration file see
`[layouts/virtual.yaml](../../layouts/virtual.yaml)`.  Then to start the daemon
run:

```
./build/keyplusd
```

NOTE: you will need root privileges to run these commands


## Debugging

To run `keyplusd` as the current user in the shell:

```
make run
```

To change the amount of debug output, change the value of the `DEBUG` flag in
the makefile to a higher value.

The default keymap layout for the `make run` command is `layouts/virtual.yaml`.
You can provide another layout file by running make with the
`TEST_CONFIG_LAYOUT` variable:

```
make run TEST_CONFIG_LAYOUT=./config.yaml
```

## Debugging - killing the daemon

To kill the daemon run:

```
kill $(cat /tmp/keyplusd.lock)
```

If you have built the project in debug mode, you can also use `DEBUG_EXIT_KEY`
to kill the daemon. By default this value is set to `~`/`KEY_GRAVE`. Note that
this is the value of the key before it is remapped by keyplus.

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
