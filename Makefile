all: $(EXECUTABLE)

.PHONY: upload clean

BOARD := "arduino:avr:nano"
PROJECT_NAME := LED_strip
OUTPUT_DIR := bin
SRC_DIR := src

EXECUTABLE := $(OUTPUT_DIR)/$(PROJECT_NAME).ino.elf

$(EXECUTABLE): $(PROJECT_NAME).ino *.h *.cpp
	arduino-cli compile -b $(BOARD) --output-dir $(OUTPUT_DIR)

upload: $(EXECUTABLE)
	arduino-cli upload -p /dev/ttyUSB0 -b $(BOARD) --board-options cpu=atmega328old --build-path $(OUTPUT_DIR)

clean:
	rm bin/*

# todo make upload query connected ports
# todo rule for changing port permissions
