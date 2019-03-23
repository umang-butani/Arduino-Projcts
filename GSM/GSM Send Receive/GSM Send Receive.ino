#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);
long randNumber;

void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module
  Serial.begin(19200);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
}

void loop()
{
  randNumber = random(1111, 9999);
  if (Serial.available() > 0)
  {
    char c = Serial.read();
    Serial.print(c);
    switch (c)
    {
      case 's':
        {
          Serial.println(randNumber);
          Serial.println("Sending Message...");
          mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
          delay(1000);  // Delay of 1000 milli seconds or 1 second
          mySerial.println("AT+CMGS=\"\"\r"); // Replace x with mobile number
          delay(1000);

          mySerial.println(randNumber);// The SMS text you want to send
          delay(100);
          
          mySerial.println((char)26);// ASCII code of CTRL+Z
          delay(1000);
          break;
        }
      case 'r':
        RecieveMessage();
        break;
    }
    if (mySerial.available() > 0)
      Serial.write(mySerial.read());
  }
}
/*
void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+91xxxxxxxxx\"\r"); // Replace x with mobile number
  delay(1000);
  Serial.println(randNumber);
  mySerial.println(randNumber);// The SMS text you want to send
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
*/
void RecieveMessage()
{
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
  delay(1000);
}
