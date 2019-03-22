#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define m11 7  
#define m12 8
#define m21 9   
#define m22 10

void m1_clk()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
}

void m1_aclk()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, HIGH);
}

void m2_up()
{
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
}

void m2_down()
{
   digitalWrite(m21, LOW);
   digitalWrite(m22, HIGH);
}

void stop()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
}
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


void setup() 
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.createChar(0, heart);
  lcd.createChar(1, smiley);
  lcd.createChar(2, frownie);
  lcd.createChar(3, armsDown);
  lcd.createChar(4, armsUp);
  lcd.print("I");
  lcd.write(byte(0));
  lcd.print("electronics___");
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
}

void loop() 
{
  lcd.setCursor(0, 1);
  for(int i =0;i<=5;i++)
  {
  m2_up();
  lcd.print("up");
  delay(300);
  
  m2_down();
  lcd.print("down");
  delay(300);
  m1_clk(); 
  //lcd.print("clk");  
 //delay(5000);                       
// m1_aclk();
  //lcd.print("aclk"); 
 //delay(5000);  
  }
 stop();
}
