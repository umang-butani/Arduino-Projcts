int r0=7;int r1=6;int r2=5;int r3=4;int c0=3;int c1=2;int c2=1;int c3=0;
int colm1;int colm2;int colm3;int colm4;

#include <Keypad.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);

void setup()
{
  pinMode(r0,OUTPUT);pinMode(r1,OUTPUT);pinMode(r2,OUTPUT);pinMode(r3,OUTPUT);
  pinMode(c0,INPUT);pinMode(c1,INPUT);pinMode(c2,INPUT);pinMode(c3,INPUT);
  Serial.begin(9600);
  digitalWrite(c0,HIGH);
  digitalWrite(c1,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(c3,HIGH);

  lcd.begin(16, 2);
  lcd.setCursor(0,0);          
  lcd.print("ADVANCED LOCKER");
}
void loop()
{
  lcd.setCursor(0,1);          
  lcd.print("OPEN(1)");

  lcd.setCursor(8,2);          
  lcd.print("NEW(2)");

  //lcd.setCursor(15,2);          
  //lcd.print("REMOVE(3)");
}

