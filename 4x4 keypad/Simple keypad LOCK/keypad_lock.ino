#include "LiquidCrystal.h"
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
char newPasswordString; //hold the new password
char newPassword[4]; //character string of newPasswordString

#include "Password.h"
Password password = Password("1234");
byte maxPasswordLength = 6;
byte currentPasswordLength = 0;


#include "Keypad.h"
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {0, 1, 2, 3}; //Rows 0 to 4
byte colPins[COLS] = {4, 5, 6, 7}; //Columns 0 to 4
int count = 0;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
  lcd.begin(16, 2);
  mainScreen();
}

void loop()
{
  char key = keypad.getKey();
  if (key != NO_KEY)
  {
    delay(60);
    switch (key)
    {
      case 'A': activate(); break;
      case 'B': break;
      case 'C': break;
      case 'D': deactivate(); break;
      case '#':  break;
      case '*': break;
      default: processNumberKey(key);
    }
  }
}

void processNumberKey(char key)
{
  lcd.print(key);
  currentPasswordLength++;
  password.append(key);
  if (currentPasswordLength == maxPasswordLength)
  {
    activate();
  }
}
void activate()
{
  if (password.evaluate())
  {
    lcd.clear();
    lcd.print("Activated.");
    delay(1000);
    mainScreen();
  }
  else
  {
    lcd.clear();
    lcd.print("Wrong Password!");
  }
}

void deactivate()
{
  if (password.evaluate())
  {
    lcd.clear();
    lcd.print("Deactivated.");
    delay(1000);
    mainScreen();
  }
  else
  {
    lcd.clear();
    lcd.print("Wrong Password!");
    delay(1000);
    mainScreen();
  }
}

void mainScreen()
{
  lcd.clear();
  lcd.print("Enter Pin:");
  keypad.getKey();
}
