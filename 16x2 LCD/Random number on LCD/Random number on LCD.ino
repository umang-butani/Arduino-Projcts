#include <LiquidCrystal.h>
LiquidCrystal lcd(14, 15, 16, 17, 18, 19);

long randNumber;    

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("  RANDOM NUMBER ");
}

void loop()
{
  randNumber = random(1111, 9999);                                              
  //Serial.println(randNumber); 
  lcd.setCursor(0, 1);
  lcd.print(randNumber);
  delay(500);
}
