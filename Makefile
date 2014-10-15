BOARD_TAG    = teensy31
ARDUINO_DIR  = /home/stepcut/n-heptane/projects/arduino/arduino-1.0.6

TARGET = blink.c
ARDUINO_LIBS =

# modify to point to where you have checked out Arduino-Makefile
#
# Use:
#
#  git clone https://github.com/sudar/Arduino-Makefile
#
# to get the source for Arduino-Makefile
include /home/stepcut/n-heptane/projects/arduino/Arduino-Makefile/Teensy.mk
