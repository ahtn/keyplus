target remote localhost:2331
file ./build/nrf52840_dk/nrf52840_xxaa.out
mon speed 10000
mon flash download=1
load
break main
