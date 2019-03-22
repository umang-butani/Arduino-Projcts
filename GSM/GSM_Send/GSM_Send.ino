void setup()
{
 Serial.begin(9600);   //Set Exact Baud rate of the GSM/GPRS Module. 
 Serial.print("\r");
 delay(1000);                  
 Serial.print("AT+CMGF=1\r");    
 delay(1000);
 Serial.print("AT+CMGS=\"+919714548574\"\r");  /*Replace XXXXXXXXXX to 10 digit mobile number &  ZZ to 2 digit country code*/   
 delay(1000);
 Serial.print("3321");   //The text of the message to be sent.
 delay(1000);
 Serial.write(0x1A);
 delay(1000); 
}
void loop()
{
}

