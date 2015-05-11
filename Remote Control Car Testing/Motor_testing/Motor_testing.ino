#include <SoftwareSerial.h>

// Amazon app commands
const int FORWARD_COMMAND = 49;
const int BACKWARD_COMMAND = 53;
const int LEFT_COMMAND = 50;
const int RIGHT_COMMAND = 52;
const int STOP_COMMAND = 51;

const int LEFT_FORWARD = 9;
const int LEFT_BACKWARD = 8;
const int RIGHT_FORWARD = 11;
const int RIGHT_BACKWARD = 10;

int Command = 0;

SoftwareSerial Remote (2,3);

void setup() {
  Remote.begin(9600);
  Serial.begin(9600);
  pinMode(LEFT_FORWARD,OUTPUT);
  pinMode(LEFT_BACKWARD,OUTPUT);
  pinMode(RIGHT_FORWARD,OUTPUT);
  pinMode(RIGHT_BACKWARD,OUTPUT);
}

void loop() {
  if (Remote.available()) 
  {
    Command = Remote.read();
    Serial.println(Command);
    
    if (Command == FORWARD_COMMAND)
    {
      moveForward();
    }
    else if (Command == BACKWARD_COMMAND)
    {
      moveBackward();
    }
    else if (Command == RIGHT_COMMAND)
    {
      moveRight();
    }
    else if (Command == LEFT_COMMAND)
    {
      moveLeft();
    }
    else if (Command == STOP_COMMAND)
    {
      moveStop();
    }
  }
}

void moveForward()
{
  digitalWrite(LEFT_FORWARD,HIGH);
  digitalWrite(LEFT_BACKWARD,LOW);
  digitalWrite(RIGHT_FORWARD,HIGH);
  digitalWrite(RIGHT_BACKWARD,LOW);
}

void moveBackward()
{
  digitalWrite(LEFT_BACKWARD,HIGH);
  digitalWrite(LEFT_FORWARD,LOW);
  digitalWrite(RIGHT_BACKWARD,HIGH);
  digitalWrite(RIGHT_FORWARD,LOW);
}
void moveRight()
{
  digitalWrite(LEFT_FORWARD,HIGH);
  digitalWrite(LEFT_BACKWARD,LOW);
  digitalWrite(RIGHT_FORWARD,LOW);
  digitalWrite(RIGHT_BACKWARD,LOW);
}
void moveLeft()
{
  digitalWrite(RIGHT_FORWARD, HIGH);
  digitalWrite(RIGHT_BACKWARD,LOW);
  digitalWrite(LEFT_FORWARD,LOW);
  digitalWrite(LEFT_BACKWARD,LOW);
}

void moveStop()
{
  digitalWrite(LEFT_FORWARD,LOW);
  digitalWrite(LEFT_BACKWARD,LOW);
  digitalWrite(RIGHT_FORWARD,LOW);
  digitalWrite(RIGHT_BACKWARD,LOW);
}
