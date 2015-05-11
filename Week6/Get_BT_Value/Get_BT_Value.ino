#include <SoftwareSerial.h>

SoftwareSerial Remote (2,3);

int Command = 0;


void setup() {
  Remote.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if (Remote.available())
  {
    Command = Remote.read();
    Serial.println(Command);
  }
}
