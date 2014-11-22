#include <LinkedList.h>
#include <stdlib.h>

#define FILTER_WINDOW 50
#define LIGHT_THRESHOLD 4

int leftForwardPin = 11;
int leftBackwardPin = 10;
int rightForwardPin = 4;
int rightBackwardPin = 2;
int leftMotorSpeedPin = 6;
int rightMotorSpeedPin = 5;


int sensor1 = A0; //inside
int sensor2 = A1; //outside

int value1;
int value2;

char tmp1[10];
char tmp2[10];

LinkedList<int> listS1 = LinkedList<int>();
LinkedList<int> listS2 = LinkedList<int>();

void setup()
{
	Serial.begin(9600);
	Serial.println("Goodnight moon!");

	for(int i=0; i<FILTER_WINDOW; i++){
	    listS1.add(analogRead(sensor1));
	    listS2.add(analogRead(sensor2));
	}

	moveForward();
	setMAXSpeed();
}

void setMAXSpeed() {
	analogWrite(leftMotorSpeedPin, 255);
  	analogWrite(rightMotorSpeedPin, 255);
}

void turnClockwise()
{
  digitalWrite(leftForwardPin, HIGH);
  digitalWrite(leftBackwardPin, LOW);
  
  digitalWrite(rightForwardPin, LOW);
  digitalWrite(rightBackwardPin, HIGH);

}

void turnCounterClockwise()
{
  digitalWrite(leftForwardPin, LOW);
  digitalWrite(leftBackwardPin, HIGH);
  
  digitalWrite(rightForwardPin, HIGH);
  digitalWrite(rightBackwardPin, LOW);

}

void moveForward()
{
  digitalWrite(leftForwardPin, HIGH);
  digitalWrite(leftBackwardPin, LOW);
  
  digitalWrite(rightForwardPin, HIGH);
  digitalWrite(rightBackwardPin, LOW);

}

void loop()
{
	int value1 = analogRead(sensor1);
	if (value1 != 0){
		listS1.add(value1);
		listS1.remove(0);
	}
	int value2 = analogRead(sensor2);
	if (value2 != 0){
		listS2.add(value2);
		listS2.remove(0);
	}

	float sum1 = 0;
	float sum2 = 0;
	for(int i=0; i<listS1.size(); i++){
	    sum1 += listS1.get(i);
	}
	float avg1 = sum1/float(listS1.size()) - 3;
	for(int i=0; i<listS2.size(); i++){
	    sum2 += listS2.get(i);
	}
	float avg2 = sum2/float(listS2.size()) - 19;

  	String stringOne = "Sensor value: ";
  	dtostrf(avg1,1,2,tmp1);
  	dtostrf(avg2,1,2,tmp2);

  	String stringThree = stringOne + tmp1 + "\t" + tmp2;
  	
  	Serial.println(stringThree);

	float realAvg = (avg2 + avg1)/2.0;

   	if (realAvg > LIGHT_THRESHOLD){
  		//black
  		turnClockwise();
  	} else {
  		//white
  		turnCounterClockwise();
  	}

	delay(1);

}
