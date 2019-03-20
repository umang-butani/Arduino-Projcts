#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
const char* ssid = "umang";
const char* password = "pppppppp";
//String analog = A0; 
int Speaker = 13; // GPIO13
WiFiServer server(80);

void setup() 
{
  Serial.begin(115200);
  delay(10);

  pinMode(Speaker, OUTPUT);
  digitalWrite(Speaker, LOW);
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
   
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print("\n Connected");
  }
}
 
void loop() 
{
if (WiFi.status() == WL_CONNECTED)  //Check WiFi connection status
   { 
    
    HTTPClient http;                 //Declare an object of class HTTPClient
    http.begin("https://www.youtube.com/channel/UCqECaJ8Gagnn7YCbPEzWH6g");
    int httpCode = http.GET();      //Send the request
    if (httpCode > 0)               //Check the returning code
     { 
      String payload = http.getString();   //Get the request response payload
      //tone(Speaker, payload);
      analogWrite(Speaker, payload);
      Serial.println(payload);             //Print the response payload
     }
    http.end();    //Close connection
   }
  delay(30000);    //Send a request every 30 seconds}
}
