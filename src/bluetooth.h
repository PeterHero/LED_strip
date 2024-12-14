#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <Arduino.h>
#include <SoftwareSerial.h>

#ifndef RXPIN
#define RXPIN 3
#endif

#ifndef TXPIN
#define TXPIN 2
#endif

class Bluetooth {
private:
  static constexpr byte _rxpin = RXPIN;
  static constexpr byte _txpin = TXPIN;
  SoftwareSerial _serial;

public:
  Bluetooth();
  void setup();
  bool read(String &message);
};

#endif
