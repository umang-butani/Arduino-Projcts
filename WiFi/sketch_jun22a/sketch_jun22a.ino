#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "nodemcu-blink.firebaseio.com"
#define FIREBASE_AUTH "TL3qoOhonvGjIrJmExyxIhexyx6qsvPipaHGugAw"
#define WIFI_SSID "umang"
#define WIFI_PASSWORD "pppppppp"

void setup() 
{
pinMode(LED_BUILTIN,OUTPUT);
digitalWrite(LED_BUILTIN,0);
Serial.begin(9600);
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("connecting");
while (WiFi.status() != WL_CONNECTED) 
  {
  Serial.print(".");
  delay(500);
  }
Serial.println();
Serial.print("connected: ");
Serial.println(WiFi.localIP());
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
Firebase.setInt("LED_BUILTINStatus",0);
}

void loop() 
{
  if(Firebase.getInt("LEDStatus"))
    {
      digitalWrite(LED_BUILTIN,HIGH);
    } 
  else
    {
      digitalWrite(LED_BUILTIN,LOW);
    }
  if (Firebase.failed()) // Check for errors 
  {
    Serial.print("failed:");
    Serial.println(Firebase.error());
    return;
  }
  delay(1000);
}
