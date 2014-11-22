
//Pin declarations
int leftForwardPin = 13;
int leftBackwardPin = 12;
int rightForwardPin = 4;
int rightBackwardPin = 2;
int leftMotorSpeedPin = 6;
int rightMotorSpeedPin = 5;
  
void setup()
{ 
  //Set digital
  
  pinMode(leftForwardPin, OUTPUT);
  pinMode(leftBackwardPin, OUTPUT);
  
  pinMode(rightForwardPin, OUTPUT);
  pinMode(rightBackwardPin, OUTPUT);
  
  pinMode(leftMotorSpeedPin, OUTPUT);
  pinMode(rightMotorSpeedPin, OUTPUT);


}

void loop()
{
  digitalWrite(leftForwardPin, LOW);
  digitalWrite(leftBackwardPin, HIGH);
  
  digitalWrite(rightForwardPin, LOW);
  digitalWrite(rightBackwardPin, HIGH);


  analogWrite(leftMotorSpeedPin, 255);
  analogWrite(rightMotorSpeedPin, 255);
}
