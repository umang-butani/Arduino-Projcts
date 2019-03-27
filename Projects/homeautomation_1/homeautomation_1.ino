#include <SPI.h>
#include <Ethernet.h>
#include <Servo.h> 
#include <SoftwareSerial.h>
SoftwareSerial mySerial_gsm(9, 10);

SoftwareSerial mySerial_bt(9, 10);
char data_gsm,c;
int count=0;

int led1 = 5;
int led2 = 6;
int led3 = 7;
char data = 0;                //Variable for storing received data

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };   //physical mac address
byte ip[] = { 10, 9, 67, 117 };                      // ip in lan (that's what you need to use in your browser. ("192.168.1.178")
byte gateway[] = { 10, 9, 67, 250 };                   // internet access via router
byte subnet[] = { 255, 255, 255, 0 };                  //subnet mask
EthernetServer server(80);                             //server port     
String readString;

void setup() 
{
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
  pinMode(led1, OUTPUT);        //Sets digital pin as output pin
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  mySerial_bt.begin(9600);
  
  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());

  mySerial_gsm.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  
  delay(100);
  mySerial_gsm.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS

  delay(1000);
}

void loop() {
  
  // Create Bluetooth Instance
  if(mySerial_bt.available() > 0)  // Send data only when you receive data:
    {
      
      data = mySerial_bt.read();      //Read the incoming data and store it into variable data
  
      if(data == '0')            //Checks whether value of data is equal to 1 
        digitalWrite(led1, HIGH);  //If value is 1 then LED turns ON
      else if(data == '1')       //Checks whether value of data is equal to 0
        digitalWrite(led1, LOW);   //If value is 0 then LED turns OFF
       if(data == '2')            //Checks whether value of data is equal to 1 
        digitalWrite(led2, HIGH);  //If value is 1 then LED turns ON
      else if(data == '3')       //Checks whether value of data is equal to 0
        digitalWrite(led2, LOW);   //If value is 0 then LED turns OFF
         if(data == '4')            //Checks whether value of data is equal to 1 
        digitalWrite(led3, HIGH);  //If value is 1 then LED turns ON
      else if(data == '5')       //Checks whether value of data is equal to 0
        digitalWrite(led3, LOW);   //If value is 0 then LED turns OFF
        if (data == '6')
        {
          digitalWrite(led1, HIGH);
          digitalWrite(led2, HIGH);
          digitalWrite(led3, HIGH);
        }
        else if(data == '7')
        {
          digitalWrite(led1, LOW);
          digitalWrite(led2, LOW);
          digitalWrite(led3, LOW);
        }
     }
    // end bluetooth
    //gsm 
    if (mySerial_gsm.available()>0)
  {
        
        data_gsm = mySerial_gsm.read();
        count++;
        if (count == 52)
        {
          c = data_gsm;
          count = 0;
          Serial.println(data_gsm);
        }
         if (c == 'A' || c=='a')
        {  
              digitalWrite(led1, (~digitalRead(led1)));
              
        }
        else{
              digitalWrite(led1,LOW);
        }

        if (c == 'B' || c=='b')
        { 
              digitalWrite(led2, (~digitalRead(led2)));
              
        }
        else{
              digitalWrite(led2,LOW);
        }
        if (c == 'D' || c=='d')
        { 
              digitalWrite(led3, (~digitalRead(led3)));
               
        }
        else{
              digitalWrite(led3,LOW);
        }
         
  }

  //end gsm
  
  // Create a client connection
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {   
      if (client.available()) {
        char c = client.read();
     
        //read char by char HTTP request
        if (readString.length() < 100) {
          //store characters to string
          readString += c;
          //Serial.print(c);
         }

         //if HTTP request has ended
         if (c == '\n') {          
           Serial.println(readString); //print to serial monitor for debuging
     
           client.println("HTTP/1.1 200 OK"); //send new page
           client.println("Content-Type: text/html");
           client.println();     
           client.println("<HTML>");
           client.println("<HEAD>");
           client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
           client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
           client.println("<link rel='stylesheet' type='text/css' href='http://randomnerdtutorials.com/ethernetcss.css' />");
           client.println("<TITLE>Atmiya - Home Automation</TITLE>");
           client.println("</HEAD>");
           client.println("<BODY>");
           client.println("<H1>Home Automation</H1>");
           client.println("<hr />");
           client.println("<br />");  
           client.println("<H2>Home </H2>");
           client.println("<br />");  
           client.println("<a href=\"/?button1on\"\">Turn On LED</a>");
           client.println("<a href=\"/?button1off\"\">Turn Off LED</a><br />");   
           client.println("<br />");     
           client.println("<br />"); 
           client.println("<a href=\"/?button2on\"\">Turn On LED</a>");
           client.println("<a href=\"/?button2off\"\">Turn Off LED</a><br />");   
           client.println("<p>Created by : Student of Atmiya.</p>");  
           client.println("<br />"); 
           client.println("</BODY>");
           client.println("</HTML>");
     
           delay(1);
           //stopping client
           client.stop();
           //controls the Arduino if you press the buttons
           if (readString.indexOf("?button1on") >0){
               digitalWrite(led1, HIGH);
           }
           if (readString.indexOf("?button1off") >0){
               digitalWrite(led1, LOW);
           }
           if (readString.indexOf("?button2on") >0){
               digitalWrite(led2, HIGH);
           }
           if (readString.indexOf("?button2off") >0){
               digitalWrite(led2, LOW);
           }
           
            //clearing string for next read
            readString="";  
           
         }
       }
    }
}
}

