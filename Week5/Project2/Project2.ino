int FruitBasket = 0;
int Apple = 0;
int Pear = 0;

void setup() {
  Serial.begin(115200);
  Apple = 2;
  Pear = 3;
  FruitBasket = Apple + Pear;
  Serial.print( "Fruit Basket = " );
  Serial.println( FruitBasket );
}

void loop() {
}
