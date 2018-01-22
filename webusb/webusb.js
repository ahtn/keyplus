
const VENDOR_ID = 0x6666

const USE_EXTRA_INTERFACE = 0

let WEBUSB_EP_NUM = 4
let WEBUSB_INTF_NUM

if (USE_EXTRA_INTERFACE) {
  WEBUSB_INTF_NUM = 5
} else {
  WEBUSB_INTF_NUM = 3
}

const CMD_ERROR_CODE = 0x00; // the response from the controller
const CMD_GET_DEVICE_SETTINGS = 0x01; // flash keyboard layout
const CMD_LED_CONTROL = 0x02; // control leds on the keyboard/receiver
const CMD_RESET = 0x03; // reset the dongle
const CMD_BOOTLOADER = 0x04; // go to the bootloader
const CMD_LAYER_STATE = 0x05; // the active layer
const CMD_LOGITECH_BOOTLOADER = 0x06; // go to the logitech bootloader
const CMD_PRINT = 0x07; // send debug data
const CMD_SET_PASSTHROUGH_MODE = 0x08; // set passthrough mode
const CMD_PASSTHROUGH_MATRIX = 0x09; // raw matrix data sent to the host without interpretting it
const CMD_UPDATE_SETTINGS = 0x0A;
const CMD_UPDATE_LAYOUT = 0x0B; // flash keyboard layout

const CMD_UNIFYING_PAIR = 0x10; // enter pairing mode


let glob_device

document.addEventListener('DOMContentLoaded', event => {
  let button = document.getElementById('connect')

  button.addEventListener('click', async() => {
    let device

    try {
      device = await navigator.usb.requestDevice({
        filters: [{
          vendorId: VENDOR_ID
        }]
      })

      console.log('open')

      await device.open()
      .then(() => {
        if (device.configuration === null) {
          return device.selectConfiguration(1);
        }
      })
      .then(() => device.selectAlternateInterface(WEBUSB_INTF_NUM, 1))
      .then(() => device.claimInterface(WEBUSB_INTF_NUM))

      console.log('opened:', device)

      let cmd = new Uint8Array(2);
      cmd[0] = CMD_BOOTLOADER
      cmd[1] = CMD_BOOTLOADER
      await device.transferOut(WEBUSB_EP_NUM, cmd)

    } catch (error) {
      console.log("Error: " + error)
    }
	  await device.close()
  })
})
