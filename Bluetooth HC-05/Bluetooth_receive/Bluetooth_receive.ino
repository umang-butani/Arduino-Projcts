#include <SoftwareSerial.h>
SoftwareSerial BT(12, 13); //TX, RX  pins of arduino respetively
String info = "";
char inChar;

void setup()
{
  Serial.begin(9600);
  BT.begin(9600);
}

void loop()
{
  while (BT.available())
  {
    inChar = (char)BT.read();  // get the new byte:
    info += inChar;           // add it to the inputString:
    Serial.print(inChar);
  }
}
