// GSM Modem SMS Sending Tutorial
// circuits4you.com
 #include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);
void setup()
{
    mySerial.begin(9600);
    Serial.begin(9600);   //Initialise serial to communicate with GSM Modem
    delay(100);
}

void loop()
{
     delay(3000); //Give enough time for GSM to register on Network
     SendSMS();    //Send one SMS
     while(1);     //Wait forever
}

void SendSMS()
{
  Serial.println("AT+CMGF=1");    //To send SMS in Text Mode
  delay(1000);
  Serial.println("AT+CMGS=\"+918849601961\"\r"); //Change to destination phone number 
  delay(1000);
  Serial.println("2222");//the content of the message
  delay(200);
  Serial.println((char)30); //the stopping character Ctrl+Z
  delay(1000);
 }

