#define trigPin1 3
#define echoPin1 2
#define trigPin2 4
#define echoPin2 5
#define buzzPin 6 

long duration, distance, RightSensor,LeftSensor;
 
void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(buzzPin,OUTPUT);
}
 
void loop()
{
SonarSensor(trigPin1, echoPin1);
RightSensor = distance;
SonarSensor(trigPin2, echoPin2);
LeftSensor = distance;
 
Serial.print(LeftSensor);
Serial.print(" - ");
//Serial.println(RightSensor);
delay(1000);

  if (LeftSensor <= 15 && LeftSensor >= 0) 
    {
      // Buzz
      digitalWrite(buzzPin, HIGH);
    }
  else 
    {
      // Don't buzz
      digitalWrite(buzzPin, LOW);
    }

}
 
void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
 
}
