all: $(EXECUTABLE)

.PHONY: upload set_port clean distclean

BOARD := "arduino:avr:nano"
PROJECT_NAME := LED_strip
OUTPUT_DIR := bin
SRC_DIR := src
PORT_FILE := port.conf

EXECUTABLE := $(OUTPUT_DIR)/$(PROJECT_NAME).ino.hex

$(EXECUTABLE): $(PROJECT_NAME).ino *.h *.cpp
	arduino-cli compile -b $(BOARD) --output-dir $(OUTPUT_DIR)

$(PORT_FILE):
	arduino-cli board list | grep /dev | cut -d " " -f1 > $(PORT_FILE)

set_port: $(PORT_FILE)
	sudo chmod o+rw $(shell cat $(PORT_FILE))

upload: $(EXECUTABLE) $(PORT_FILE)
	arduino-cli upload -p $(shell cat $(PORT_FILE)) -b $(BOARD) --board-options cpu=atmega328old --build-path $(OUTPUT_DIR)

clean:
	rm $(OUTPUT_DIR)/*

distclean: clean
	rm $(PORT_FILE)
