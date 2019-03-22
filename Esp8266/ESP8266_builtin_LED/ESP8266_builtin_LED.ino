/*
  ESP8266 Blink
  Blink the blue LED on the ESP-12 module

  The blue LED on the ESP-12 module is connected to GPIO2
  (which is also the TXD pin; so we cannot use Serial.print() at the same time)
*/
#include <EEPROM.h>

#define LED 2   //Define connection of LED
#define D4  16 //Switch
unsigned long tok = 0;
boolean settingMode;

struct WifiCreds
{
  char ssid[30] = "";
  char pass[30] = "";
  boolean reset_status = false;
} apdata;


void setup() {
  Serial.begin(115200);
  //EEPROM.begin(513);
  pinMode(LED,INPUT);
  pinMode(D4, INPUT);
  //attachInterrupt(D4, highInterrupt, RISING);
  //digitalWrite(D4, HIGH);
  /*
  EEPROM.get(0, apdata);
    if (apdata.reset_status) {
      settingMode = true;
      apdata.reset_status = false;
      setupMode();
    }
    else {
      if (restoreConfig())
      {
        if (checkConnection())
        {
          settingMode = false;
        }
        else
        {
          settingMode = true;
          setupMode();
        }
      }
    }
    */                
}
/*
void highInterrupt()
{
  Serial.println("_OK_");
  //led = LOW;
  attachInterrupt(D4, highInterrupt, FALLING);
  Serial.println("O_K_");

  for (int i = 0; i < 513; ++i)
  {
    EEPROM.write(i, 0);
    ++tok;
  }
  EEPROM.commit();
  if (tok == 513)
  {
    Serial.println("EEPROM killed correctly");
  }
  Serial.println("clear");
  apdata.reset_status = true;
  EEPROM.put(0, apdata);
  EEPROM.commit();
  Serial.println("2 Reset Status: " + apdata.reset_status);
  //setupMode();
}
*/

// the loop function runs over and over again forever
void loop()
{
  digitalWrite(LED, LOW);  
  digitalWrite(D4, HIGH);// Turn the LED on (Note that LOW is the voltage level but actually the LED is on; this is because it is active low on the ESP-12)
  Serial.print("LED on :.)");
  delay(1000);              // Wait for a second
  digitalWrite(LED, HIGH); 
  digitalWrite(D4, LOW);// Turn the LED off by making the voltage HIGH
  Serial.print("LED off :.(");
  delay(1000); // Wait for two seconds (to demonstrate the active low LED)
}
