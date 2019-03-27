#include<Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = 
{
  {'1','1','2','3'},
  {'4','4','5','6'},
  {'7','7','8','9'},
  {'*','*','0','#'}
};
byte rowPins[ROWS] = {11,10,9,8}; //connect to the row pinouts of the keypad
byte colPins[COLS] =  {7,6,5,4};//connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
char customKey=0;
char password[4];
int i=0;

String Entered_OTP = "";

//#include <SoftwareSerial.h>
//SoftwareSerial mySerial(9, 10);

#include<SoftwareSerial.h>
SoftwareSerial BT(12, 13); //TX, RX  pins of arduino respetively

#include<LiquidCrystal.h>
LiquidCrystal lcd(14, 15, 16, 17, 18, 19); // initialize the library with the numbers of the interface pins RS,EN,D4,D5,D6,D7

String Aadhar="";
String info="";
volatile int count=0;
char inChar;
boolean stringComplete = false;  // whether the string is complete
int flag = 0;

long randNumber;
long OTP;

//----------//Aadhar data//-------------//
String P1="390177559845";
