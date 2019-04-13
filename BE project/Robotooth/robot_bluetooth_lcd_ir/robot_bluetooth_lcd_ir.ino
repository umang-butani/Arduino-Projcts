#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int ProxSensor=6;

#define m11 7  
#define m12 8
#define m21 9   
#define m22 10
char str[2],i;
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
  lcd.begin(16, 2);
  pinMode(13,OUTPUT);
  lcd.print("____ROBOTOOTH___");
  pinMode(ProxSensor,INPUT);
  Serial.begin(9600);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
}

void loop() 
{
  if(digitalRead(ProxSensor)==HIGH)      //Check the sensor output
  {
    digitalWrite(13,HIGH);
    delay(100); 
    Stop();
  }
  else
  {
  lcd.setCursor(0, 1);
  lcd.print("DESIGN ENGI...");
  while(Serial.available())
   {
    char ch=Serial.read();
    str[i++]=ch;
    
    if(str[i-1]=='1')
    {
     Serial.println("Forward");
     forward();
     i=0;
    }
    else if(str[i-1]=='2')
    {
     Serial.println("right");
     right();
     i=0;
    }
    else if(str[i-1]=='3')
    {
      Serial.println("BACKWARD");
      backward();
      i=0;
    }
    
    else if(str[i-1]=='4')
    {
      Serial.println("left");
      left();
      i=0;
    }
    else if(str[i-1]=='5')
    {
      Serial.println("Stop");
      Stop();
      i=0;
    }
    delay(100);
  }
  }
  
}
