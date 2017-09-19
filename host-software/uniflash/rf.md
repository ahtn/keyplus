## Channel switching

* nRF24 supports 128 channels, controlled by `RF_CH` register
* channel frequency is `2400 + RF_CH` MHz
* At 2Mbps, channels overlap and need to be spaced ±2MHz
* Uses channels `x*3 + 2`
* Some devices don't use all the channels in that range
