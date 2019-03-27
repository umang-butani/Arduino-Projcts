void loop()
{
  lcd.setCursor(0, 1);
  lcd.print("SCAN AADHAR CARD");
  randNumber = random(1111, 9999);
  char customKey = keypad.getKey();
  //Serial.println(customKey );
  
  while (BT.available())
  //while (Serial.available()) 
  {
    inChar = (char)BT.read();  // get the new byte:
    //inChar = (char)Serial.read();  // get the new byte:
    info += inChar;           // add it to the inputString:
    //Serial.print(inChar);
    count ++; // if the incoming character is a newline, set a flag so the main loop can do something about it:
    
    if (inChar == '@') 
    {
      Serial.println("Clossing...");
      Close();
    }
    if (inChar == '\n') 
     {
       info="";
       Aadhar = info;
       flag =1;
     }
    if(info.length()>29 && info.length()<42)
     {
       Aadhar+=inChar;
     }
    if (info.length() > 40 && flag==1)
     {
      Serial.println(Aadhar);
      info = "";
      {
      if(Aadhar == P1)
        { 
         Serial.println(randNumber);
         OTP==randNumber;
         Open();
    
         /*mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
         delay(1000);  // Delay of 1000 milli seconds or 1 second
         mySerial.println("AT+CMGS=\"+918849339407\"\r"); // Replace x with mobile number
         delay(1000);
         Serial.println(randNumber);
         mySerial.println(randNumber);
         delay(100);
         mySerial.println((char)26);// ASCII code of CTRL+Z
         delay(1000);
         */
          
          /*do
          {
            if (Serial.available()>0)
              {
                char customKey = keypad.getKey();
                Entered_OTP += (char) customKey;
              }
           }while(Entered_OTP.length() < 4);
            Serial.println(Entered_OTP);
            int temp_OTP = Entered_OTP.toInt();
            if(temp_OTP == OTP)
              {
                Open();
              }
            else
              {
                Serial.println("Wrong OTP");
              }
              */
      }            
      else
        {
          Serial.println("unAuthorized User");
          lcd.setCursor(0, 1);
          lcd.print("unAuthorized User");
        }
      }
        flag=0;
    }
    
 }
}
