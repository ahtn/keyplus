
TODO: automate this this stuff

## Dependencies

The current python dependencies: `intelhex pyusb`

## Flashing a unifying receiver


```sh

sudo ./uniflash.py icp
sleep 2
sudo ./uniflash.py info

```

Check that `mcu is nRF24LU1+`. Note not all unifying receivers use the same
microprocessor. Only devices that use the nRF24LU1+ are supported. If your
device is supported, you should then be able to run the following command
to flash a hex file to it:

```sh
sudo ./uniflash.py flash <target_hex_file>
```

## Restore Unifying receiver firmware.

If you would like to restore the back to the original unifying receiver
firmware, you can use the [firmware hex files provide by logitech here](
https://github.com/Logitech/fw_updates/tree/master/RQR12
).
