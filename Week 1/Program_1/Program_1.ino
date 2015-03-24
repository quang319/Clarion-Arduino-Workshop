 void setup() {
  pinMode(13, OUTPUT);  //Set pin 2 as an OUTPUT
}

void loop() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}
