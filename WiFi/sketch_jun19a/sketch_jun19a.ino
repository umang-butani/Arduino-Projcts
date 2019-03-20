#include <ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80);
const char* ssid = "dj";
const char* password = "djdjdjdj";

void setup() 
{
  Serial.begin(115200);
  connectWiFi();
  server.begin();
}

void loop() 
{
}

/* connecting WiFi */
void connectWiFi()
{
  Serial.println("Connecting to WIFI");
  WiFi.begin(ssid, password);
  while ((!(WiFi.status() == WL_CONNECTED)))
  {
    delay(300);
    Serial.print("..");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("NodeMCU Local IP is : ");
  Serial.print((WiFi.localIP()));
}
