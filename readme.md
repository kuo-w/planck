# Planck Rev6

User guide to flashing a Planck, or possibly any QMK supported keyboard.

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
	- `qmk compile -kb _keyboard_ -km _keymap_`
	- Example:
  	```
	qmk compile -kb planck/rev6 -km mine
	```
1. Retrieve .bin
	- Example:
	```
	cp -f qmk_firmware/.build/planck_rev6_mine.bin /mnt/c/projects/qmk
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

- Get Zadig
- Enter DFU mode (space+b)
- Select STM32 BOOTLOADER
- Install libusbK
- Open qmk toolbox
- Re-enter DFU mode
- Flash
