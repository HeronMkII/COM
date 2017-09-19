# coms

The this project contains the main program running on the coms board.

## Instruction to build and run from scratch

The following information is outdated; TODO: revise.

First, install [homebrew](https://brew.sh/). Next, do

```
$ brew tap osx-cross/avr
$ brew install avr-libc
$ brew install avrdude --with-usb
```

This intalls the AVR GCC toolchain along with software to write binary files
to the ATMega's flash memory.

It may also be necessary to patch `avrdude.conf` to support the m32m1. This can
be found online.

To build the program, run

```
$ make
```

To upload the program to the MCU, run

```
$ make upload
```

## Finding the correct USB port

To see all connected USB devices do

```
$ ls /dev/tty.usb*
```

The USB device corresponding to the programmer is almost always the device
with the lowest id. To ease compilation, open the makefile and change the
value of `PORT` to this device's location. For example, if the command
above returns `/dev/tty.usbmodem00100561 /dev/tty.usbmodem00100563`,
set the value of `PORT` to `/dev/tty.usbmodem00100561`.
