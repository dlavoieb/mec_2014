

int forward = 13;
int backward = 12;
  
void setup()
{ 
  pinMode(forward, OUTPUT);
  pinMode(backward, OUTPUT);

}

void loop()
{
  digitalWrite(forward, LOW);
  digitalWrite(backward, HIGH);


  analogWrite(6, 255); 
}
