void Open()
{
 Serial.println("Opening");
 lcd.setCursor(0, 1);
 lcd.print("Please Wait Opening");
 digitalWrite( 2,HIGH);
 digitalWrite( 3,LOW);
 delay(2000);
 digitalWrite( 2,LOW);
}
void Close()
{
  digitalWrite( 3,HIGH);
  digitalWrite( 2,LOW);
  lcd.setCursor(0, 1);
  lcd.print("Please Wait Cloasing....");
  delay(1000);
  digitalWrite( 3,LOW);
}
