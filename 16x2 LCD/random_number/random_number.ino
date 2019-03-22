// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(14,15,16,17,18,19);

long randNumber;                                                            // the variable which is supposed to hold the random number
const int analogOutPin = 6;  // Analog output pin where the LED is attached to
long OTP;

void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("random number");
  lcd.setCursor(0, 1);
  //lcd.print("  RANDOM NUMBER ");
  // initialize the serial port
  Serial.begin(9600);
  // initialize the pseudo-random number generator
  randomSeed(analogRead(0));
}

void loop()
{
  randNumber = random(1111, 9999);                                              // generate a random number
  //Serial.println(randNumber);                                               // send the random number to the serial port
  OTP = randNumber;
  analogWrite(analogOutPin, randNumber); // vary the brightness of the LED according to the random number
  lcd.setCursor(0, 1);
  lcd.print(randNumber);
  Serial.println(OTP);
  delay(3000);
}
