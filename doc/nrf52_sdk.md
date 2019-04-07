# nRF52 Flashing and SDK notes

## Downloading the SDK

* [SDK download page](https://www.nordicsemi.com/Software-and-Tools/Software/nRF5-SDK)
https://www.nordicsemi.com/DocLib?Product=SDK%20Documentation)
* [SDK documentation](https://www.nordicsemi.com/DocLib?Product=SDK%20Documentation)

### SDK 15.3.0

* [SDK 15.3.0](https://www.nordicsemi.com/-/media/Software-and-other-downloads/SDKs/nRF5/Binaries/nRF5SDK153059ac345.zip
* [SDK 15.3.0 Offline Documentation](http://developer.nordicsemi.com/nRF5_SDK/nRF5_SDK_v15.x.x/nRF5_SDK_15.3.0_offline_doc.zip)


## ARM toolchain

Uses the ARM gcc for compiling.

Arch Linux:
```
sudo pacman -S arm-none-eabi-gcc arm-none-eabi-newlib
```

## Compiling nRF52 SDK examples

When compiling the SDK examples, you can provide the install location of ARM
gcc like this:

```
export GNU_INSTALL_ROOT=/usr/bin/
export GNU_PREFIX=arm-none-eabi
make
```

The example folders have targets for different boards.

* pca10056  -> nRF52840-DK
* pca10056e -> nRF52840-DK (emulates the nRF52811 using nRF52840-DK)
* pca10040  -> nRF52-DK
* pca10040e -> nRF52-DK (emulates the nRF52810 using nRF52832-DK)

Inside a board directory there may be several sub-folders for targeting
different softdevices and bootloaders. Inside these folders look for the
`armgcc` folder for the relevant makefile for compiling with `gcc`. E.g.
`pca10056/blank/armgcc`.

### Programming nRF5x with J-Link

Nordic provides the `nrfjprog` tool to program nRF5x chips using SEGGER
J-Link programmers and debuggers.

The nRF52 dev kits include an onboard J-Link programmer.  Using the [debug
output pins](
https://www.nordicsemi.com/DocLib/Content/User_Guides/nrf52840_dk/latest/UG/nrf52840_DK/hw_debug_out)
the dev kit can be used as a J-Link programmer for other nRF51 and nRF52
boards.

* [nRF52840 dev kit doc](https://www.nordicsemi.com/DocLib/Content/User_Guides/nrf52840_dk/latest/UG/nrf52840_DK/intro)

#### Installing nRF5X command line tools

* [Installing nRF5x command line tools.](https://www.nordicsemi.com/DocLib/Content/User_Guides/nrf5x_cltools/latest/UG/cltools/nrf5x_installation)
* [SEGGER JLink](https://www.segger.com/downloads/jlink/#J-LinkSoftwareAndDocumentationPack) required for nRF5x tools to work on Mac and Linux.

Arch Linux aur package: [`nrf5x-command-line-tools`](https://aur.archlinux.org/packages/nrf5x-command-line-tools/)

#### Examples of using nRF5x cli tools

##### Reading device memory

```
nrfjprog -f NRF52 --readcode readback.hex
```

Can also use `--readram` to read device RAM.


##### Flashing a hex file

```
nrfjprog -f NRF52 --program file.hex --chiperase
```

When compiling the examples from the nRF52 SDK, you can use

```
make flash
```

If the example uses Bluetooth, you will also need to program a softdevice
separately. To program the softdevice, run

```
make flash_softdevice
```

### nRF52 SDK debugging

#### NRF52_LOG

The nrf52 SDK provides a logging utility that runs over UART or the J-Link RTT
(Real Time Terminal). To enable the logging functions you need to configure
them in the `sdk_config.h` file.

You can set this values manually in `sdk_config.h` or run the provided java
applet with:

```
make sdk_config
```

Before the using UART or RTT logging, the code must call these two functions:

```
ret_code_t err_code = NRF_LOG_INIT(NULL);
NRF_LOG_DEFAULT_BACKENDS_INIT();
```

NOTE: some of the examples in the nRF52 SDK don't call the
`NRF_LOG_DEFAULT_BACKENDS_INIT()` function, so you might need to add it
yourself before the examples will log over UART or RTT.

##### UART Logging output

To enable UART logging set both `NRF_LOG_ENABLED` and
`NRF_LOG_BACKEND_UART_ENABLED` in `sdk_config` and disable RTT logging if
necessary. By default the SDK examples are configured to use UART, so you
should be able to skip this step if you haven't modified them.

Then you need to use a serial terminal program to view the UART output. For
example using `screen` run:

```
picocom -b 115200 /dev/ttyACM0
```

To exit press press C-A C-X. For a nicer GUI alternative you could try `putty`
or `moserial`.

* [List of serial terminal programs](https://wiki.archlinux.org/index.php/working_with_the_serial_console#Making_Connections)

##### RTT Logging output

To enable RTT logging set both `NRF_LOG_ENABLED` and
`NRF_LOG_BACKEND_RTT_ENABLED` in `sdk_config` and disable UART logging if
necessary.

You then need to run the J-Link RTT Viewer program (JLinkRTTViewerExe). Then
you should be able to connect to your device and view the log output.
