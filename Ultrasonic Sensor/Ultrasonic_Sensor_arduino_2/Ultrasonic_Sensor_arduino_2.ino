#define trigPin1 2
#define echoPin1 3
#define buzzPin 4
#include <Servo.h>  // servo library

Servo servo1;  // servo control object
Servo servo2;

long duration, distance, UltraSensor;
int position;
 
void setup()
{
Serial.begin (9600);

pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(buzzPin,OUTPUT);

servo1.attach(9);
servo2.attach(10);
}
 
void loop()
{
SonarSensor(trigPin1, echoPin1);
//UltraSensor = distance;
Serial.println(distance);
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
delay(100);

}
