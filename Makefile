all: upload

.PHONY: compile upload clean

BOARD := "arduino:avr:nano"
BUILD_DIR := build

compile:
	arduino-cli compile -b $(BOARD) --build-path $(BUILD_DIR) .

upload: compile
	arduino-cli upload -p /dev/ttyUSB0 -b $(BOARD) --board-options cpu=atmega328old --build-path $(BUILD_DIR) .

clean:
	rm -r build/*

# todo make upload query connected ports
# todo rule for changing port permissions
# create dependencies so that compile or update is not run when not needed
