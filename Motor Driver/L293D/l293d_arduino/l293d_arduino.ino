#define m11 6  
#define m12 7
#define m21 8   
#define m22 9

void forward()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
}
void backward()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, HIGH);
   digitalWrite(m21, LOW);
   digitalWrite(m22, HIGH); 
}
void left()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   delay(100);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
}
void right()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   delay(100);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
}
void Stop()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);  
   digitalWrite(m22, LOW);
}
void setup() 
{
  Serial.begin(9600);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
}

void loop() 
{
  forward();
}
