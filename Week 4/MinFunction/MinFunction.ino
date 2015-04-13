
int MinPin = 0;

void setup() {
}

void loop() {
  MinPin = findMinPin();

}

int findMinPin()
{
  int MinimumPin = 0;
  
  if (analogRead(0) > analogRead(1)) {
    MinimumPin = 1;
  }
  if (analogRead(MinimumPin) > analogRead(2)) {
    MinimumPin = 2;
  }
  if (analogRead(MinimumPin) > analogRead(3)) {
    MinimumPin = 3;
  }
  
  return MinimumPin;
}
