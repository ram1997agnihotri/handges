/*
* Gesture Recognition Robot 
*/
int xPin=A3; //X axis input
int yPin=A2; //Y axis input
int D1=10,D2=11,D3=12,D4=13; //Output pins to be connected to 10, 11, 12, 13 of Decoder IC
long x; //Variabe for storing X coordinates
long y; //Variabe for storing Y coordinates
void setup()
{
  Serial.begin(9600);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
}
void loop()
{
  x = analogRead(xPin); 
  y = analogRead(yPin); 
    if(x<340)      // Change the value for adjusting sensitivity  
      forward();
    else if(x>400) // Change the value for adjusting sensitivity
      backward();
    else if(y>400) // Change the value for adjusting sensitivity
      right();
    else if(y<340) // Change the value for adjusting sensitivity
      left();
    else
      stop_();
}
void stop_()
{
  Serial.println("");
  Serial.println("STOP");
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);
  digitalWrite(D3,LOW);
  digitalWrite(D4,LOW);
}
void forward()
{
  Serial.println("");
  Serial.println("Forward");
  digitalWrite(D1,HIGH);
  digitalWrite(D2,LOW);
  digitalWrite(D3,HIGH);
  digitalWrite(D4,LOW);
}
void backward()
{
  Serial.println("");
  Serial.println("Backward");
  digitalWrite(D1,LOW);
  digitalWrite(D2,HIGH);
  digitalWrite(D3,LOW);
  digitalWrite(D4,HIGH);
}
void left()
{
  Serial.println("");
  Serial.println("Left");
  digitalWrite(D1,LOW);
  digitalWrite(D2,HIGH);
  digitalWrite(D3,HIGH);
  digitalWrite(D4,LOW);
}
void right()
{
  Serial.println("");
  Serial.println("Right");
  digitalWrite(D1,HIGH);
  digitalWrite(D2,LOW);
  digitalWrite(D3,LOW);
  digitalWrite(D4,HIGH);
}
