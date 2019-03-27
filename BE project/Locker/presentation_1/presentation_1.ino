#include <Keypad.h>
#include <LiquidCrystal.h>
//#include <SoftwareSerial.h>

//SoftwareSerial mySerial(10,11);         //from gsm tx>10 rx>11
LiquidCrystal lcd(14,15,16,17,18,19);  // initialize the library with the numbers of the interface pins

long randNumber;     
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
char code[4];                       //Hold pressed keys

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad customKeypad = Keypad( makeKeymap(Keys), rowPins, colPins, ROWS, COLS);     //initialize an instance of class NewKeypad 

void setup()
{
 // mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);
    
}
  
void loop()
{
  char customKey = customKeypad.getKey();      //read pressed key
  Serial.print(customKey);
  
}

