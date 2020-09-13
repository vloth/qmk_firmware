# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = lite # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no    # Mouse keys
EXTRAKEY_ENABLE = yes   # Audio control and System control
CONSOLE_ENABLE = no     # Console for debug
COMMAND_ENABLE = no     # Commands for debug and configuration
SLEEP_LED_ENABLE = no   # Breathing sleep LED during USB suspend
NKRO_ENABLE = no        # USB Nkey Rollover
BACKLIGHT_ENABLE = no   # Enable keyboard backlight functionality on B7 by default
RGBLIGHT_ENABLE = yes   # Enable keyboard RGB underglow
MIDI_ENABLE = no        # MIDI support
UNICODE_ENABLE = no     # Unicode
BLUETOOTH_ENABLE = no   # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no       # Audio output on port C6
FAUXCLICKY_ENABLE = no  # Use buzzer to emulate clicky switches
HD44780_ENABLE = no 	  # Enable support for HD44780 based LCDs

TAP_DANCE_ENABLE = yes
ENCODER_ENABLE = yes
MOUSEKEY_ENABLE = no
KEY_LOCK_ENABLE = no
