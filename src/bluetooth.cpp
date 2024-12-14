#include "bluetooth.h"

Bluetooth::Bluetooth() : _serial(_rxpin, _txpin) {}

void Bluetooth::setup() {
  pinMode(_rxpin, INPUT);
  pinMode(_txpin, OUTPUT);

  //_serial = SoftwareSerial(_rxpin, _txpin);

  _serial.begin(9600);
}

bool Bluetooth::read(String &message) {
  if (_serial.available() > 0) {
    message = _serial.readString();
    return true;
  } else
    return false;
}
