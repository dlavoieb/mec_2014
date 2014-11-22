#define straight1 57
#define straight2 26
#define straight3 24
#define straight4 16

#define turn1 100

#define speed 

int leftForwardPin = 11;
int leftBackwardPin = 10;
int rightForwardPin = 4;
int rightBackwardPin = 2;
int leftMotorSpeedPin = 6;
int rightMotorSpeedPin = 5;

void setup()
{
  pinMode(leftForwardPin, OUTPUT);
  pinMode(leftBackwardPin, OUTPUT);
  
  pinMode(rightForwardPin, OUTPUT);
  pinMode(rightBackwardPin, OUTPUT);
  
  pinMode(leftMotorSpeedPin, OUTPUT);
  pinMode(rightMotorSpeedPin, OUTPUT);
 
}

void setMAXSpeed() {
  analogWrite(leftMotorSpeedPin, 255);
    analogWrite(rightMotorSpeedPin, 255);
}

void moveForward()
{
  digitalWrite(leftForwardPin, HIGH);
  digitalWrite(leftBackwardPin, LOW);
  
  digitalWrite(rightForwardPin, HIGH);
  digitalWrite(rightBackwardPin, LOW);

}

void turnCounterClockwise()
{
  analogWrite(leftMotorSpeedPin, 100);
  analogWrite(rightMotorSpeedPin, 255);

}

void turnClockwise()
{
  analogWrite(leftMotorSpeedPin, 255);
    analogWrite(rightMotorSpeedPin, 100);

}

void loop()
{
  setMAXSpeed();
  moveForward();
  int delay1 = straight1/speed;
  delay(delay1);
  turnCounterClockwise();
  delay(turn1);
  moveForward();
  int delay2 = straight2/speed;
  delay(delay2);
  turnCounterClockwise();
  delay(turn1);
  moveForward();
  int delay3 = straight3/speed;
  delay(delay3);
  turnCounterClockwise();
  delay(turn1);
  moveForward();
  int delay4 = straight4/speed;
  delay(delay4);
  turnClockwise();
  delay(turn1);
  moveForward(); 
}
