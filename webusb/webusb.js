
const VENDOR_ID = 0x6666

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
      console.log('device_thingy: '+ device)
      let glob_device = device
      await device.open()
      console.log('opened:', device)
    } catch (error) {
      console.log("Error: " + error)
    }
	  await device.close()
  })
})
