# Planck Rev6

Flashing instructions

## Pre-requisites

QMK Firmware

## Compile Keymap

1. Create a keymap path
	- Should look like: `<path_to_qmk_firmware>/keyboards/_keyboard_/keymaps/_keymap_`
	- Inside should contain a file `keymap.c`
	- Example:
	```
	cp -f /mnt/c/projects/qmk/keymap.c ~/qmk_firmware/keyboards/planck/keymaps/mine
	```
1. Compile
	- `cd _dir_ && qmk compile`
	- Example:
  	```
  	cd /home/wkuo/qmk_firmware/keyboards/planck/keymaps/mine
	qmk compile
	```
1. Retrieve .bin
	- Example:
	```
	cp -f ~/qmk_firmware/.build/planck_rev6_mine.bin /mnt/c/projects/qmk
	```

## Flash

1. Launch qmk_toolbox
1. Go into flash mode
	- Disconnect kb
	- Hold spacebar + B
	- Connect kb
1. Flash .bin file

## Errors

Qmk toolbox saying it can't list HID devices?

Prerequisites:

- Zadig

1. Enter DFU mode (space+b)
1. Open Zadig
1. Select STM32 BOOTLOADER
1. Install libusbK/WinUSB
1. Open qmk toolbox
1. Re-enter DFU mode
1. Flash
