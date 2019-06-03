# linux keyplus emulator

* NOTE/TODO: device selection is still hard-coded in `src/device_manager.c`
* TODO: device mapping for mouse buttons

## Debugging

To run `keyplusd` as the current user in the shell:

```
make run
```

To change the amount of debug output, change the value of the `DEBUG` flag in
the makefile to a higher value.

The default keymap layout for the `make run` command is `layouts/virtual.yaml`.

## Run as daemon

Need to create the `keyplusd` user and add `udev` rules. Run the `./setup.sh`
to do this.  After running this script you may need to reboot for some of the
`udev` rules to take effect.

```
sudo ./build/keyplusd -c <path to binary config>
```

NOTE: since the daemon runs as the `keyplusd` user, make sure the config file
is located where the `keyplusd` user will have read access.

To see log output from the daemon, use:

```
journalctl -b -f
```
