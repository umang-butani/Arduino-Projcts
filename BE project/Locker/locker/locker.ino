/*
  Aadhar base Locker system
  
  by Umang Butani(umangbutani@gmail.com)
  Date:02-04-2018
*/

//#include <SoftwareSerial.h>
//SoftwareSerial mySerial(9, 10);

#include<SoftwareSerial.h>
SoftwareSerial BT(12, 13); //TX, RX  pins of arduino respetively

#include<LiquidCrystal.h>
//LiquidCrystal lcd(14, 15, 16, 17, 18, 19); // initialize the library with the numbers of the interface pins RS,EN,D4,D5,D6,D7
LiquidCrystal lcd(7,6,5,4,3,2);

String Aadhar="";
String info="";
volatile int count=0;
char inChar;
boolean stringComplete = false;  // whether the string is complete
int flag = 0;

long randNumber;
long OTP;

//----------//Aadhar data//-------------//
String P1="390177559845";

void setup()
{
   Serial.begin(9600); 
   BT.begin(9600);
// mySerial.begin(9600);  
   //lcd.begin(16, 2);
  // lcd.print("ADVANCE LOCKER SYSTEM");
  
}
  
void loop()
{
  
//  lcd.setCursor(0, 1);
  //lcd.print("SCAN AADHAR CARD");
  randNumber = random(1111, 9999);

  while (BT.available())
  //while (Serial.available()) 
  {
    inChar = (char)BT.read();  // get the new byte:
    info += inChar;           // add it to the inputString:
    count ++; // if the incoming character is a newline, set a flag so the main loop can do something about it:
    
    if (inChar == '@') 
    {
      Serial.println("Clossing...");
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
      if(Aadhar == P1)
        { 
         Serial.println(randNumber);
         BT.write(randNumber);
         OTP==randNumber;

        Open();
         /*
         mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
         delay(1000);  // Delay of 1000 milli seconds or 1 second
         mySerial.println("AT+CMGS=\"+918849339407\"\r"); // Replace x with mobile number
         delay(1000);
         mySerial.println(OTP);
         delay(100);
         mySerial.println((char)26);// ASCII code of CTRL+Z
         delay(1000);

         while (BT.available()) 
           {
             inChar = (char)BT.read();  // get the new byte:
             if(inChar == OTP)
             {
              Open();
             }
           }
          */
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
 delay(2000);
 digitalWrite( 2,LOW);
}
void Close()
{
  digitalWrite( 3,HIGH);
  digitalWrite( 2,LOW);
  delay(1000);
  digitalWrite( 3,LOW);
}
