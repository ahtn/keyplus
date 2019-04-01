# Disabling libinput button debouncing for a device on Linux

The [libinput library provise software button debouncing](
https://wayland.freedesktop.org/libinput/doc/latest/button-debouncing.html)
on Linux. However, this can sometimes cause issues when running macros on
devices. It's possible do disable this feature for a device using [device
quirks](https://wayland.freedesktop.org/libinput/doc/latest/device-quirks.html).

To disable software debouncing on a keyplus device create, create the file
[`/etc/libinput/local-overrides.quirks`](../host-software/etc/libinput)
with the following contents.

```
[keyplus mouse]
MatchUdevType=mouse
MatchBus=usb
MatchVendor=0x1209
MatchProduct=0xBB00
ModelBouncingKeys=1

[keyplus keyboard]
MatchUdevType=keyboard
MatchBus=usb
MatchVendor=0x1209
MatchProduct=0xBB00
ModelBouncingKeys=1
```

Then run `sudo udevadm hwdb --update` and reboot the system for the settings
to take effect.
