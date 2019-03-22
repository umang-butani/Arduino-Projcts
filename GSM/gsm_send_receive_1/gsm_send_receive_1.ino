//ERFINDER CODE
#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);
long randNumber;
void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
}
void loop()
{
  randNumber = random(1111, 9999);
  if (Serial.available()>0)
   switch(Serial.read())
  {
    case 's':
      SendMessage();
      break;
    case 'r':
      RecieveMessage();
      break;
  }
 if (mySerial.available()>0)
   Serial.write(mySerial.read());
}
 void SendMessage()
{
  Serial.println("Sending msg");
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+918849339407\"\r"); // Replace x with mobile number
  delay(1000);
  Serial.println(randNumber);
  mySerial.println(randNumber);// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
 void RecieveMessage()
{
  Serial.println("Recieving");
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to recieve a live SMS
  delay(1000);
 }

