# EFM8 Port IO modes

![EFM8 IO](https://rawgit.com/ahtn/keyplus/master/doc/imgs/efm8_io.png)

## Registers control bits:
* XBARE: Crossbar Enable. If crossbar is disabled only pull-up resistors are
  active (provide WEAKPUD=0), and pins can't be driven HI or LO.
* WEAKPUD: Disable Weak pull-up resistors on all IO pins
* PxMDOUT.x: (1 for push-pull, 0 for open-drain) (PxMDOUT=0 -> disable drive high)
* PxMDIN.x: Analog/Digital (1 for digital, 0 for analog)
* Px.x: Input/Output Logical value

Note: All examples Below assumes WEAKPUD=0

## Default values:
* XBARE     = 0
* PxMDOUT.x = 0
* PxMDIN.x  = 1

Px.x==1 -> Weak pull up
Px.x==0 -> Weak pull up

No output. Can read value of pin with Px.x

## Default values after enabling XBARE:
Open drain with pull-up:
* XBARE     = 1
* PxMDOUT.x = 0
* PxMDIN.x  = 1 -> Digital

Px.x==1 -> Weak pull up
Px.x==0 -> Drive low

## Pin configured for analog input:
* XBARE     = 1
* PxMDOUT.x = 0
* PxMDIN.x  = 0 -> Analog (Px reads 0)

Px.x==1 -> Floating
Px.x==0 -> Floating

## Pin configured for analog input with drive high:
* XBARE     = 1
* PxMDOUT.x = 1
* PxMDIN.x  = 0 -> Analog (Px reads 0)

Px.x==1 -> Drive high
Px.x==0 -> Floating

## Pin configured as push-pull
* XBARE     = 1
* PxMDOUT.x = 1
* PxMDIN.x  = 1 -> Digital

Px.x==1 -> Drive high
Px.x==0 -> Drive low
