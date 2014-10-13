VENDOR       = teensy
BOARD_TAG    = teensy31
 # this is in boards.txt, but there is a chicken and egg problem reading that
ARCHITECTURE = arm-none-eabi

ARDUINO_DIR         = /home/stepcut/n-heptane/projects/arduino/arduino-1.0.6
ARDUINO_CORE_PATH   = $(ARDUINO_DIR)/hardware/teensy/cores/teensy3
BOARDS_TXT          = $(ARDUINO_DIR)/hardware/$(VENDOR)/boards.txt

F_CPU=72000000

TARGET = blink.c
ARDUINO_LIBS =

include /home/stepcut/n-heptane/projects/arduino/Arduino-Makefile/Arduino.mk

value:
	@echo $(CXXFLAGS)
# uploadt:
#	/home/stepcut/n-heptane/projects/arduino/arduino-1.0.6/hardware/tools/teensy


# COMPILERPATH = $(ARDUINO_DIR)/hardware/tools/arm-none-eabi/bin
# AVR_TOOLS_DIR = $(ARDUINO_DIR)/hardware/tools/arm-none-eabi
# CC = $(abspath $(COMPILERPATH))/arm-none-eabi-gcc
#CXX = $(AVR_TOOLS_PATH)/arm-none-eabi-g++
#OBJCOPY = $(AVR_TOOLS_PATH)/arm-none-eabi-objcopy
#SIZE = $(AVR_TOOLS_PATH)/arm-none-eabi-size
# NO_CORE_MAIN_CPP = "fee"
# CPPFLAGS += -mthumb -nostdlib -MMD -D__MK20DX256__ -DTEENSYDUINO=120 -DUSB_SERIAL -DLAYOUT_US_ENGLISH
# CPPFLAGS += -DUSB_SERIAL -DLAYOUT_US_ENGLISH -DF_CPU=96000000
# CXXFLAGS += -std=gnu++0x  -felide-constructors
#CXXFLAGS += -std=gnu++0x -felide-constructors -fno-exceptions -fno-rtti
#LDFLAGS  += -Os -Wl,--gc-sections -mcpu=cortex-m4 -mthumb -Tmk20dx256.ld
# LDFLAGS  += -Tmk20dx256.ld

#ALTERNATE_CORE_PATH = $(ARDUINO_DIR)/hardware/teensy/
# these are really MCPU and CPU flags
#MCU_FLAG_NAME=mcpu
#MCU=cortex-m4
