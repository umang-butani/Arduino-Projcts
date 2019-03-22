#include<LiquidCrystal.h>  
LiquidCrystal lcd(14,15,16,17,18,19); 
int row[]={7,6,5,4};// Defining row pins of keypad connected to Arduino pins
int col[]={3,2,1,0};//Defining column pins of keypad connected to Arduino
int i,j,lcd_count,count=1,key_id=0,flag,entry=0;// See About the Program 
int col_scan;// Variable to identify a key press
char temp_press; // Variable to hold value of key press
char check[6],pass[6]; // See About the Program

void setup()
{
lcd.begin(16,2);
for(i=0;i<=3;i++)
{
pinMode(row[i],OUTPUT);
pinMode(col[i],INPUT);
digitalWrite(col[i],HIGH);
}
lcd.print("SET 5 Digit PASS");
}
/* Main Program Begins */
void loop()
{
  lcd.setCursor(0,0);           //sets the cursor at row 0 column 0
  lcd.print("16x2 LCD MODULE"); // prints 16x2 LCD MODULE
  lcd.setCursor(2,1);           //sets the cursor at row 1 column 2
  lcd.print("HELLO WORLD");     // prints HELLO WORLD
  while(entry<=4)// Password Setting Loop begins
  {
    }
}


