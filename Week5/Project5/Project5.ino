const int NUMBER_OF_NOTES = 2;
const int THRESHOLD = 50;
int Limit = 0;
int LowestPin = 0;

void setup() {
  delay(2000);
  Limit = analogRead(0);
  Limit = Limit - THRESHOLD;
  Serial.begin(115200);
  Serial.println("Ready!");
}

void loop() {
  for (int i = 0; i < (NUMBER_OF_NOTES - 1); i++) 
  {
    if ( analogRead(i) < analogRead(i + 1) ) {
      LowestPin = i;
    }
    else {
      LowestPin = i + 1;
    }
  }
  
  if (analogRead(LowestPin) < Limit) 
  {
    Serial.print("Note ");
    Serial.print(LowestPin);
    Serial.println(" is being played");
  }

}
