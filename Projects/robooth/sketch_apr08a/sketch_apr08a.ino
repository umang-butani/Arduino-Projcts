#include <Servo.h>
Servo servopick;
Servo servoup;
int position;
// motor pin defines
#define MOTOR_R_0    10
#define MOTOR_R_1    11
#define MOTOR_L_0    8
#define MOTOR_L_1    9
// Define pins for ultrasonic
#define trigPin1 2
#define echoPin1 3
long duration, distance;


void setup()
{
  Serial.begin (9600);
  // initialize Sensor.
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  //Motor initialization
  pinMode(MOTOR_R_0, OUTPUT);
  pinMode(MOTOR_R_1, OUTPUT);
  pinMode(MOTOR_L_0, OUTPUT);
  pinMode(MOTOR_L_1, OUTPUT);
  servopick.attach(13);
  servoup.attach(12);
  //All Pin to low
  digitalWrite(MOTOR_R_0, LOW);
  digitalWrite(MOTOR_R_1, LOW);
  digitalWrite(MOTOR_L_0, LOW);
  digitalWrite(MOTOR_L_1, LOW);
}

void loop()
{
  SonarSensor(trigPin1, echoPin1);
  Serial.println(distance);

  if (distance <= 20)
  {
    Stop();
    Buzz();
    Pick();
    Right();
    delay(500);
    Stop();
    Put();
    Left();
    delay(500);
    Stop();
  }
  else
  {
    Forward();
  }

}

void Forward(void)
{
  digitalWrite(MOTOR_R_0, LOW);
  digitalWrite(MOTOR_R_1, HIGH);
  digitalWrite(MOTOR_L_0, LOW);
  digitalWrite(MOTOR_L_1, HIGH);
}
void Revers(void)
{
  digitalWrite(MOTOR_R_0, HIGH);
  digitalWrite(MOTOR_R_1, LOW);
  digitalWrite(MOTOR_L_0, HIGH);
  digitalWrite(MOTOR_L_1, LOW);
}
void Stop(void)
{
  digitalWrite(MOTOR_R_0, LOW);
  digitalWrite(MOTOR_R_1, LOW);
  digitalWrite(MOTOR_L_0, LOW);
  digitalWrite(MOTOR_L_1, LOW);
}
void Left(void)
{
  digitalWrite(MOTOR_R_0, LOW);
  digitalWrite(MOTOR_R_1, HIGH);
  digitalWrite(MOTOR_L_0, LOW);
  digitalWrite(MOTOR_L_1, LOW);
}
void Right()
{
  digitalWrite(MOTOR_R_0, LOW);
  digitalWrite(MOTOR_R_1, LOW);
  digitalWrite(MOTOR_L_0, LOW);
  digitalWrite(MOTOR_L_1, HIGH);
}
void Pick()
{
  servoup.write(0);
  delay(1000);
  servopick.write(180);
  delay(1000);
  servoup.write(60);
  delay(1000);
  servopick.write(90);
  delay(1000);
  servoup.write(0);
  delay(1000);

}

void Put()
{
  servopick.write(90);
  delay(1000);
  servoup.write(0);
  delay(1000);
  servoup.write(70);
  delay(1000);
  servopick.write(180);
  delay(1000);
  servoup.write(0);
  delay(1000);
}

void Buzz()
{
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
}
void SonarSensor(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  delay(100);
}
