#include <SoftwareSerial.h>
SoftwareSerial BT(12, 13); //TX, RX  pins of arduino respetively
String info="";

String Aadhar="";
volatile int count=0;
char inChar;
long randNumber;
boolean stringComplete = false;  // whether the string is complete
int flag = 0;

void setup() 
{
  Serial.begin(9600);
  BT.begin(9600);
}

void loop() 
{
  randNumber = random(1111, 9999);
  while (BT.available()) 
{
      inChar = (char)BT.read();  // get the new byte:
      info += inChar;           // add it to the inputString:
      Serial.print(inChar);
  }
}

