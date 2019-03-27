#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(14,15,16,17,18,19);  // initialize the library with the numbers of the interface pins RS,EN,D4,D5,D6,D7

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char Keys[ROWS][COLS] =
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'<','0','E','D'}
};                                  //define the cymbols on the buttons of the keypads

char keycount=0;
char code[10];                       //Hold pressed keys

byte rowPins[ROWS] = {0,1,2,3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4,5,6,7}; //connect to the column pinouts of the keypad

Keypad customKeypad = Keypad( makeKeymap(Keys), rowPins, colPins, ROWS, COLS);     //initialize an instance of class NewKeypad 

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("ADVANCE LOCKER SYSTEM");
  
}
  
void loop()
{
  //lcd.autoscroll();
  char customKey = customKeypad.getKey();      //read pressed key
  lcd.setCursor(0,0);
  lcd.print("ADVANCE LOCKER  ");
  delay(100);
  lcd.setCursor(0,1);
  lcd.print("OPEN(A)"); 
   if(customKey == 'A')
    {
      Open();    //PROCESS FOR OPEn
    }
}

void Open()
{
digitalWrite(11,HIGH);
digitalWrite(10,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
delay(350);
digitalWrite(11,LOW);
delay(10000);
digitalWrite(11,LOW);
digitalWrite(10,HIGH);
delay(350);
digitalWrite(10,LOW);
delay(20);
digitalWrite(8,LOW);
}
