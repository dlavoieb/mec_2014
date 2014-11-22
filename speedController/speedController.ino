

int forward = 13;
int backward = 12;
int leftMotorPin = 6;
int rightMotorPin = 7;
  
void setup()
{ 
  pinMode(forward, OUTPUT);
  pinMode(backward, OUTPUT);

}

void loop()
{
  digitalWrite(forward, LOW);
  digitalWrite(backward, HIGH);


  analogWrite(leftMotorPin, 255);
  analogWrite(rightMotorPin, 255);
}
