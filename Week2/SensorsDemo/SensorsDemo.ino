// constants won't change. They're used here to set pin numbers:
const int BUTTON_PIN = 12;
const int LED_PIN = 10;
const int PHOTOCELL_PIN = 0;
const int PIEZO_PIN = 3;

// variables will change:
int ButtonState = 0;
int PrevButtonState = 0;
int State = 0;
int PhotocellValue = 0;
bool PiezoIsPlaying = false;

void setup() {
  // initialize the LED and Piezo Buzzer pins as an outputs:
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIEZO_PIN, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(BUTTON_PIN, INPUT);
  // analog pins are automatically setup as inputs
  
  Serial.begin(115200);
}

void loop() {
  /**************************************************************
  /
  /        This part just reads the presses of the button 
  /        and increment the state variable
  /
  /*************************************************************/
  
  // read the state of the pushbutton and debounce the button
  ButtonState = digitalRead(BUTTON_PIN);
  delay(50);
  // These statements ensure that the code only increment the variable State
  // when the button is on the rising edge. 
  if ((PrevButtonState == 0) && (ButtonState == 1)) {
    State++;
    PrevButtonState = 1;
  }
  else if ( (PrevButtonState == 1) && (ButtonState == 0)) {
    PrevButtonState = 0;
  }
  
  /**************************************************************
  /
  /        This part uses the various sensors
  /
  /*************************************************************/
  // Button State
  if ( State == 1 ) {
    Serial.println("You are in the button state");  
  }
  
  // LED State
  else if ( State == 2 ) {
    Serial.println("Turning on LED");
    digitalWrite(LED_PIN, HIGH);
  }
  
  // Photocell State
  else if ( State == 3 ) {
    digitalWrite(LED_PIN, LOW);
    PhotocellValue = analogRead(PHOTOCELL_PIN);
    Serial.println(PhotocellValue);
  }
  
  // Piezo Buzzer State
  else if ( State == 4 ) {
    if (PiezoIsPlaying == false){
      tone(PIEZO_PIN, 30);
      Serial.println("Piezo buzzer is playing");
      PiezoIsPlaying = true;
    }
  }
  
  // Return back to normal state
  else {
    if (PiezoIsPlaying == true) {
      noTone(PIEZO_PIN);
      PiezoIsPlaying = false;  
    }
    State = 0;
  }
}
