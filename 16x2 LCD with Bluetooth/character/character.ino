#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
/*
byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};
byte smiley_tung_in[8] = {
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00100,
  0b00000
};
byte smiley_tung_out[8] = {
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000,
  0b00000
};
byte star[8] = {
  0b00000,
  0b00000,
  0b00100,
  0b11111,
  0b01110,
  0b10001,
  0b00000,
  0b00000
};
byte circle[8] = {
  0b00000,
  0b00000,
  0b01110,
  0b10001,
  0b10101,
  0b10001,
  0b01110,
  0b00000
};
byte lines_odd[8] = {
  0b00000,
  0b11111,
  0b00000,
  0b11111,
  0b00000,
  0b11111,
  0b00000,
  0b11111
};
byte lines_even[8] = {
  0b11111,
  0b00000,
  0b11111,
  0b00000,
  0b11111,
  0b00000,
  0b11111,
  0b00000
};
byte lines_c_odd[8] = {
  0b01010,
  0b01010,
  0b01010,
  0b01010,
  0b01010,
  0b01010,
  0b01010,
  0b01010,
};
byte lines_c_even[8] = {
  0b10101,
  0b10101,
  0b10101,
  0b10101,
  0b10101,
  0b10101,
  0b10101,
  0b10101
};
byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};
byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};
byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};
*/
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  
}

void loop()
{
  
  /*
  lcd.createChar(1, smiley);
  lcd.createChar(2, frownie);
  lcd.createChar(3, armsDown);
  lcd.createChar(4, armsUp);
  lcd.createChar(5, heart);
  lcd.createChar(6, star);
  lcd.createChar(7, smiley_tung_in);
  lcd.createChar(8, smiley_tung_out);
  lcd.createChar(9, circle);
  lcd.createChar(10, lines_odd);
  lcd.createChar(11, lines_even);
  lcd.createChar(12, lines_c_odd);
  lcd.createChar(13, lines_c_even);
  */
  lcd.setCursor(0, 0);
  lcd.print("I");
  lcd.write(5);
  lcd.print("electronics___");
  lcd.setCursor(1, 1);
  //lcd.write(1);
  lcd.setCursor(2, 1);
  //lcd.write(2);
  lcd.setCursor(3, 1);
  //lcd.write(3);
  lcd.setCursor(4, 1);
  //lcd.write(4);
  lcd.setCursor(5, 1);
  lcd.write(5);
  lcd.setCursor(6, 1);
  //lcd.write(6);
  lcd.setCursor(7, 1);
  //lcd.write(7);
  lcd.setCursor(8, 1);
  //lcd.write(8);
  lcd.setCursor(9, 1);
  //lcd.write(9);
  lcd.setCursor(10, 1);
  //lcd.write(10);
  lcd.setCursor(11, 1);
  //lcd.write(11);
  lcd.setCursor(12, 1);
  //lcd.write(12);
  lcd.setCursor(13, 1);
  //lcd.write(13);
}
