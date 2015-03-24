const int MY_LED = 13;
const int DOUBLE_COUNT = 5;
const int MAX_SCORE = 50;

int  Score = 0;
int  BlinkCounter = 0;

void setup() {
  
  Serial.begin(115200);      //Establish serial connection
  pinMode(MY_LED, OUTPUT);  //Set pin 2 as an OUTPUT

}

void loop() {
  
  //If we haven't reached the max score
  if (Score <= MAX_SCORE) {
    //Blink the LED
    digitalWrite(MY_LED, HIGH);
    delay(1000);
    digitalWrite(MY_LED, LOW);
    delay(1000);
    
    //If we haven't reach double points
    if (BlinkCounter < DOUBLE_COUNT) {
      BlinkCounter = BlinkCounter + 1;\
      Score = Score + 1;
    }
    
    // If double point has been reached
    else {
      BlinkCounter = 0;
      Score = Score * 2;
    }
    
    Serial.print("Your score is: ");
    Serial.println(Score);    
  }
  
  // If max score has been reached
  else {
    Serial.println("Congratulation!! You won!!");
    digitalWrite(MY_LED,HIGH);
    delay(5000);  
  }
}
