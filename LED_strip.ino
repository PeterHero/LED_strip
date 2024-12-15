#include "src/strip_controller.h"
#include <SoftwareSerial.h>

StripController strip;
CRGB colors[] = {CRGB::Red, CRGB::Green, CRGB::Blue};
size_t colors_size = sizeof(colors) / sizeof(colors[0]);
constexpr size_t TIME = 500;

constexpr byte rxPin = 3;
constexpr byte txPin = 2;
SoftwareSerial bluetooth(rxPin, txPin);

void setup() {
    strip.setup();
    strip.simple(CRGB::Blue, 10);

    Serial.begin(9600);

    pinMode(rxPin, INPUT);
    pinMode(txPin, OUTPUT);
    bluetooth.begin(9600);
    bluetooth.println("Arduino here");
}

void stripLineEnding(String& message) {
    if (message.endsWith("\r\n")) {
        message.remove(message.length() - 2, 2);
    }
    else if (message.endsWith("\r") || message.endsWith("\n")) {
        message.remove(message.length() - 1);
    }
}

String nextWord(String& message) {
    String word;
    int index = message.indexOf(" ");

    if (index == -1) {
        word = message;
        message = "";
    } else if (index == message.length() - 1) {
        word = message.substring(0, index);
        message = "";
    } else {
        word = message.substring(0, index);
        message = message.substring(index + 1);
    }

    return word;
}

void serveCommand(String cmd) {
    String word = nextWord(cmd);
    if (word == "start") {
        strip.simple(CRGB::Green, 10);
    } else if (word == "stop") {
        strip.simple(CRGB::Red, 10);
    } else {
        strip.simple(CRGB::Blue, 10);
    }
}

void handleRequest(String message) {
    stripLineEnding(message);

    String word;

    word = nextWord(message);

    if (word == "CMD") {
        serveCommand(message);
    } else if (word != "+DISC:SUCCESS" && word != "OK") {
        bluetooth.print("unknown command: ");
        bluetooth.println(word);
        bluetooth.println("Expected: CMD {arguments}");
    }
}

void loop() {
    if (bluetooth.available() > 0) {
      handleRequest(bluetooth.readStringUntil('\n'));
    }
}
