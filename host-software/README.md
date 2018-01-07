
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

Program a device based on it's serial
```
./keyplus_cli.py progarm --serial 5W162 --layout layout_file.yaml
```

Some commands need a target device to operate on. In the case that multiple
matching devices are present, the first device will be used. So for example:
```
./keyplus_cli.py progarm --layout layout_file.yaml
```
