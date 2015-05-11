#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(2,3);
int ledpin = 13;
int Data = 0;

void setup() {
  Bluetooth.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if (Bluetooth.available()) {
    Serial.println(Bluetooth.read());
  }
}
