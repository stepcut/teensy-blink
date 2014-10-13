BOARD_TAG    = teensy31
ARDUINO_DIR  = /home/stepcut/n-heptane/projects/arduino/arduino-1.0.6

TARGET = blink.c
ARDUINO_LIBS =

include Teensy.mk
include /home/stepcut/n-heptane/projects/arduino/Arduino-Makefile/Arduino.mk
