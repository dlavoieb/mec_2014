#define straight1 59
#define straight2 26
#define straight3 24
#define straight4 16

#define turn1 1500

#define speed 3.1788

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
digitalWrite(leftForwardPin, LOW);
  digitalWrite(leftBackwardPin, HIGH);
  
  digitalWrite(rightForwardPin, HIGH);
  digitalWrite(rightBackwardPin, LOW);
}

void turnClockwise()
{
digitalWrite(leftForwardPin, HIGH);
  digitalWrite(leftBackwardPin, LOW);
  
  digitalWrite(rightForwardPin, LOW);
  digitalWrite(rightBackwardPin, HIGH);
}

void loop()
{
  setMAXSpeed();
  moveForward();
  float delay1 = straight1/speed * 1000;
  delay(delay1);
  turnCounterClockwise();
  delay(turn1);
  moveForward();
  int delay2 = straight2/speed * 1000;
  delay(delay2);
  turnCounterClockwise();
  delay(turn1);
  moveForward();
  int delay3 = straight3/speed * 1000;
  delay(delay3);
  turnCounterClockwise();
  delay(turn1);
  moveForward();
  int delay4 = straight4/speed * 1000;
  delay(delay4);
  turnClockwise();
  delay(turn1);
  moveForward(); 
}
