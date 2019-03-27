/*
  Aadhar base Locker system
  
  by Umang Butani(umangbutani@gmail.com)
  Date:02-04-2018
*/

#include<SoftwareSerial.h>
SoftwareSerial BT(12, 13); //TX, RX  pins of arduino respetively
#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);

String Aadhar="";
String info="";
volatile int count=0;
char inChar;
boolean stringComplete = false;  // whether the string is complete
int flag = 0;
//----------//Aadhar data//-------------//
String P1="390177559845";        // Change your AADHAAR data here
String P2="644084935126";
void setup()
{
   Serial.begin(9600); 
   BT.begin(9600);
   //lcd.begin(16, 2);
   // lcd.print("ADVANCE LOCKER SYSTEM");
  
}
  
void loop()
{
  lcd.setCursor(0, 1);
  lcd.print("SCAN AADHAR CARD");
  while (BT.available())
  {
    inChar = (char)BT.read();  // get the new byte:
    info += inChar;           // add it to the inputString:
    count ++; // if the incoming character is a newline, set a flag so the main loop can do something about it:
    
    if (inChar == '@') 
    {
      Close();
    }
    if (inChar == '\n') 
    {
      info="";
      Aadhar = info;
      flag =1;
    }
    if(info.length()>29 && info.length()<42)
    {
      Aadhar+=inChar;
    }
    if (info.length() > 40 && flag==1)
    {
      Serial.println(Aadhar);
      info = "";
      {
        if(Aadhar == P2)
          { 
            Open();
          }            
        else
          {
            lcd.setCursor(0, 1);
            lcd.print("unAuthorized User");
            Serial.println("unAuthorized User");
          }
      }
    flag=0;
    }
 }
}

void Open()
{
 Serial.println("Opening....");
 digitalWrite( 2,HIGH);
 digitalWrite( 3,LOW);
 delay(700);
 digitalWrite( 2,LOW);
}
void Close()
{
  Serial.println("Closing....");
  digitalWrite( 3,HIGH);
  digitalWrite( 2,LOW);
  delay(1000);
  digitalWrite( 3,LOW);
}
