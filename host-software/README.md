
Python dependencies

```
PySide pyyaml cffi hexdump intelhex
```

Other dependencies: hidapi

## GUI programming tool

To run the GUI programming tool
```
./loader.py
```

## Command line tool

A command line tool to control keyplus devices is also provided. For a list of
avaliable commands run

```
./keyplus_cli.py -h
```

Program a device based on it's serial:
```
./keyplus_cli.py progarm --serial 5W162 --layout layout_file.yaml
```

Program a device giving it a new device id:
```
./keyplus_cli.py progarm --new-id 11 --layout_file layout_file.yaml --rf rf_file.yaml
```
When no flags are given to target a specific device, the first device found
will be used. However, if multiple devices are connected, then this command
will fail and require you to add flags to target a specific device or
disconnect the other devices.
