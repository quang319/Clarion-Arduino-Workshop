const int LED_PIN = 13;

int EndOfProgram = 0;
int BlinkCounter = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() 
{
  for (int BlinkCounter = 0; BlinkCounter <= 15; BlinkCounter++)
  {
    ledBlink(LED_PIN);
  }
  EndOfProgram = 1;
  while( EndOfProgram == 1) 
  {
    ; // This loop we go on forever.
  }
}

void ledBlink(int pin) 
{
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
  delay(1000);
}
