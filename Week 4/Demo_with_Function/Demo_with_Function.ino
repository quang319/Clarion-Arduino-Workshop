const int LED_PIN = 13;

int EndOfProgram = 0;
int BlinkCounter = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
      
  if (EndOfProgram == 0)
  {
    ledBlink(LED_PIN);  
    BlinkCounter++;
    if (BlinkCounter >= 15) 
      EndOfProgram = 1;
  }
  else
    ;// We do nothing here
}

void ledBlink(int pin) 
{
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
  delay(1000);
}
