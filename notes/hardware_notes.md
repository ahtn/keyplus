# Hardware notes

## Main component datasheet links

* [ATxmega-A4U](http://www.atmel.com/images/Atmel-8387-8-and16-bit-AVR-Microcontroller-XMEGA-A4U_Datasheet.pdf)
* [nRF24L01+](https://www.nordicsemi.com/eng/content/download/2726/34069/file/nRF24L01P_Product_Specification_1_0.pdf). Minimum operating voltage is 1.9V, so this is the limiting factor for when the battery is considered dead.
* [nRF24LU1+](https://www.nordicsemi.com/eng/content/download/2724/34051/file/nRF24LU1P_Product_Spec_v1_1.pdf)
* [MCP1700 (3.3V voltage regulator)](http://ww1.microchip.com/downloads/en/DeviceDoc/20001826D.pdf)
* [BAT54c (power supply ORing)](https://www.diodes.com/assets/Datasheets/ds11005.pdf)

### Note: BAT54c for power supply ORing
Might want to switch to MOSFET power supply ORing, but this is simpler/cheaper
and the considering the trades below don't seem to bad on paper. The typical
voltage drop across the diodes at ~10mA is 350mV, which means our
minimum operating voltage will be at about 1.9V + 0.35V = 2.25V.

This is okay for CR2032 since their discharge curve is relatively flat and lies
between 2.9V and 2.6V for most of their discharge cycle.

For 2xAAA, that means we are effectively dead at 1.1V per a cell. The cutoff
voltage is more varied for AAA cells since there are multiple battery
chemistries to consider and the discharge curves seem to be more varied among
different manufacturers.

* For rechargeable NiMH batteries (e.g. eneloops) have a relatively
flat discharge curve that sits at 1.2V and drops rapidly when the battery is
nearly depleted. So with 2 cells, we have 2.4V available, so this shouldn't
cause any problems.
* Alkaline batteries have a more linear discharge curve. With our cutoff of 1.1V
it is possible to utilize about 80% of the energy stored in them.

## AAA battery datasheets

* [Duracell battery datasheets](https://www.duracell.com/en-us/techlibrary/product-technical-data-sheets)
* [Energizer](http://data.energizer.com/pdfs/e92.pdf)
* [Panasonic NiMH](https://www.kronium.cz/uploads/BK-3MCCE.pdf)
* [Panasonic alkaline-zinc/magnanese dioxide AA battery datasheet](https://na.industrial.panasonic.com/sites/default/pidsa/files/panasonic_alkaline_aa_lr6xwa_datasheet.pdf)

## Useful links about CR2032 and low power operation

* [CR2032 discharge curves](http://www.low-powerdesign.com/121312-article-extending-battery-life.htm)
* [CR2032 battery characteristics](http://www.embedded.com/electronics-blogs/break-points/4429960/How-much-energy-can-you-really-get-from-a-coin-cell-). Considering the maximum operating current is important for determining usable battery capacity.
* [Useful info about ceramic capacitors](http://www.embedded.com/electronics-blogs/break-points/4430050/Using-a-capacitor-to-sustain-battery-life). Be aware of DC-bias voltage derating.
* [Sleep current vs active current](http://www.embedded.com/electronics-blogs/break-points/4418098/2/A-sneak-preview). Sleep current is probably going to be dwarfed by operating current, so as long as it is in the low μA range, reducing opperating current is more important.

## USB

* [USB in a NutShell](http://www.beyondlogic.org/usbnutshell/usb1.shtml)
* [HID spec](http://www.usb.org/developers/hidpage/HID1_11.pdf)
* [HID usage tables](http://www.usb.org/developers/hidpage/Hut1_12v2.pdf)
* [Using USB 2.0 with USB Type-C connector](http://www.st.com/resource/en/application_note/dm00235987.pdf)

## Boost convert for 1xAAA/AA battery operation

* [TPS6122x](http://www.ti.com/lit/ds/symlink/tps61222.pdf)
