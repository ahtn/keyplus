
Python dependencies

```
PySide pyyaml cffi hexdump intelhex
```

Other dependencies: hidapi

## GUI programming tool

To run the GUI programming tool
```
./keyplus_flasher.py
```

## Command line tool

A command line tool to control keyplus devices is also provided. For a list of
avaliable commands run

```
./keyplus_cli.py -h
```

Program a device with the given serial number:
```
./keyplus_cli.py program --serial 5W162 --layout layout_file.yaml
```

Program a device giving it a new device id:
```
./keyplus_cli.py program --new-id 11 --layout layout_file.yaml --rf rf_file.yaml
```
Note since we didn't give a serial number, device id, etc. this command would
attempt to program any connected device.
