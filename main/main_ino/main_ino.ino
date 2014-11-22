#include <LinkedList.h>

#define FILTER_WINDOW 10
#define DIFF_THREASHOLD 100

int leftMotorPIN = 9;
int rightMotorPIN = 10;

int sensor1 = A0;
int sensor2 = A1;

int prev1;
int prev2;
int value1;
int value2;

LinkedList<int> listS1 = LinkedList<int>();
LinkedList<int> listS2 = LinkedList<int>();

void setup()
{
	for(int i=0; i<FILTER_WINDOW; i++){
	    listS1.add(analogRead(sensor1));
	    listS2.add(analogRead(sensor2));
	}
}

void loop()
{
	listS1.add(analogRead(sensor1));
	listS1.remove(0);
	listS2.add(analogRead(sensor2));
	listS2.remove(0);

	float sum1 = 0;
	float sum2 = 0;
	for(int i=0; i<listS1.size(); i++){
	    sum1 += listS1.get(i);
	}
	float avg1 = sum1/float(listS1.size());
	for(int i=0; i<listS2.size(); i++){
	    sum2 += listS2.get(i);
	}
	float avg2 = sum2/float(listS2.size());

	int diff1 = prev1 - avg1;
	int diff2 = prev2 - avg2;

	if (diff1 < DIFF_THREASHOLD){ //check orientation of logic 
	//less light, less current, less voltage, negative differential
		//moved from white to black

	}
	else {
		//moved from black to white
	}

}
