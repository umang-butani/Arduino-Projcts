void setup()
{
   Serial.begin(9600);
   BT.begin(9600);
   //mySerial.begin(9600);  
   lcd.begin(16, 2);
   lcd.print("ADVANCE LOCKER SYSTEM");
}
  
