const int THRESHOLD = 50;
int Limit = 0;

void setup() {
  delay(2000);
  Limit = analogRead(0);
  Limit = Limit - THRESHOLD;
  Serial.begin(115200);

}

void loop() {
  if (analogRead(0) < Limit) 
  {
    Serial.println("Note1 is being played");
  }
  else 
  {
    Serial.println("Note1 is not being played");
  }
  delay(1000);

}
