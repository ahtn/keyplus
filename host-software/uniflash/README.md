
TODO: automate this this stuff

## Dependencies

The current python dependencies: `intelhex pyusb`

## Flashing a unifying receiver


```sh

sudo ./uniflash.py icp
sleep 2
sudo ./uniflash.py info

```

Check that `mcu is nRF24LU1+`, then

```sh
sudo ./uniflash.py flash <target_hex_file>
```

