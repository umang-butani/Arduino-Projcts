/*This example contis simple Arduino and Ultrsonics sensor intrfacing */
#define trigPin1 2
#define echoPin1 3
#define buzzPin 4

long duration, distance, UltraSensor;
int position;

void setup()
{
  Serial.begin (9600);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(buzzPin, OUTPUT);
}

void loop()
{
  SonarSensor(trigPin1, echoPin1);
  Serial.println(distance);
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
