const int PLAYER1_PIN = 12;
const int PLAYER2_PIN = 11;
const int GAME_LED_PIN = 7;

long RandomNumber;
bool NewGame = true;
int Player1Button = 0;
int Player2Button = 0;

void setup() {
  // Start Serial Communication
  Serial.begin(115200);
  //This start the seed (source for the random #) for the random number generator
  randomSeed(analogRead(0));
  // Set the pins to their proper mode
  pinMode(PLAYER1_PIN, INPUT);
  pinMode(PLAYER2_PIN, INPUT);
  pinMode(GAME_LED_PIN, OUTPUT);

}

void loop() {
  if (NewGame == true){
    NewGame = false;
    // Tell the user it's a new game and make sure the LED is off
    Serial.println("New Game!");
    digitalWrite(GAME_LED_PIN, LOW);
    // Get random number for between 1s and 10s
    RandomNumber = random(1000, 10000);
    // Delay by this random period
    delay(RandomNumber);
    // Turn on LED to tell the user to press the button
    digitalWrite(GAME_LED_PIN, HIGH);
  }
  else {
    // read the 2 players' button
    Player1Button = digitalRead(PLAYER1_PIN);
    Player2Button = digitalRead(PLAYER2_PIN);
    // If player 1 presses the button first
    if ( Player1Button == 1 ) {
        Serial.println("Player 1 wins!");
        // Wait 5 second before starting a new game
        delay(5000);
        NewGame = true;
    }
    else if ( Player2Button == 1 ) {
        Serial.println("Player 2 wins!");
        // Wait 5 second before starting a new game
        delay(5000);
        NewGame = true;
    }
  }
  
  

}
