const int MY_LED = 13;

void setup() 
{
  pinMode(MY_LED, OUTPUT);
  Serial.begin(115200);
}

void loop() 
{
  for (int i = 0; i < 10; i++) 
  {
    delay(1000);
    digitalWrite(MY_LED, HIGH);
    delay(1000);
    digitalWrite(MY_LED, LOW);
    Serial.print("i = ");
    Serial.println( i );
  }
  while(1)
  {
    Serial.println("I'm Done!");
    delay(5000);
  }
    
  
}
