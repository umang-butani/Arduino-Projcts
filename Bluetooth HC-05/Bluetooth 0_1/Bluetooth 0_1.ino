String inputString = "";

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  if (Serial.available())
  {
    while (Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input
      inputString += inChar;        //make a string of the characters coming on serial
      if (inputString == "1")
      {
        digitalWrite(13, HIGH);
      }
      else if (inputString == "0")
      {
        digitalWrite(13, LOW);
      }
    }
    Serial.println(inputString);
    inputString = "";
  }
}
