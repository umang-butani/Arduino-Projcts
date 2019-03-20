#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "umang";
const char* password = "pppppppp";

void setup () 
{
  Serial.begin(115200);
  Serial.print("Connecting..");
  WiFi.begin(ssid, password);
  pinMode(D5, OUTPUT);
  while (WiFi.status() != WL_CONNECTED) 
  {
   delay(1000);
   Serial.print("..");
  }
  Serial.print("\n Connected");
}

void loop() 
{
  if (WiFi.status() == WL_CONNECTED)  //Check WiFi connection status
   { 
    
    HTTPClient http;                 //Declare an object of class HTTPClient
    http.begin("http://www.electronicwings.com/nodemcu/nodemcu-i2c-with-arduino-ide");
    int httpCode = http.GET();      //Send the request
    if (httpCode > 0)               //Check the returning code
     { 
      String payload = http.getString();   //Get the request response payload
      Serial.println(payload);             //Print the response payload
     }
    http.end();    //Close connection
   }
  delay(30000);    //Send a request every 30 seconds
}
