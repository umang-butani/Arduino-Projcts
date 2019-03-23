#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);
char data, c;
int count = 0;

int led1 = 5;
int led2 = 6;
int led3 = 7;

void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  pinMode(led1, OUTPUT);        //Sets digital pin as output pin
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  delay(100);
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
  delay(1000);
}


void loop()
{
  if (mySerial.available() > 0)
  {

    data = mySerial.read();
    count++;
    if (count == 52)
    {
      c = data;
      count = 0;
      Serial.println(data);
    }
    if (c == 'A' || c == 'a')
    {
      digitalWrite(led1, (~digitalRead(led1)));

    }
    else 
    {
      digitalWrite(led1, LOW);
    }

    if (c == 'B' || c == 'b')
    {
      digitalWrite(led2, (~digitalRead(led2)));

    }
    else 
    {
      digitalWrite(led2, LOW);
    }
    if (c == 'D' || c == 'd')
    {
      digitalWrite(led3, (~digitalRead(led3)));
    }
    else 
    {
      digitalWrite(led3, LOW);
    }

  }
}
