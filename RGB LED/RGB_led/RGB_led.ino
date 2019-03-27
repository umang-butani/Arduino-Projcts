#define R 0  
#define G 1  
#define B 2   
#define GN 3
long randNumber;     
void red()
{
   digitalWrite(R, LOW);digitalWrite(G, HIGH);digitalWrite(B, HIGH);digitalWrite(GN, HIGH);
}
void green()
{
   digitalWrite(R, HIGH);digitalWrite(G, LOW);digitalWrite(B, HIGH);digitalWrite(GN, HIGH);
}
void blue()
{
   digitalWrite(R, HIGH);digitalWrite(G, HIGH);digitalWrite(B, LOW);digitalWrite(GN, HIGH);
}
void r_g()
{
   digitalWrite(R, LOW);digitalWrite(G, LOW);digitalWrite(B, HIGH);digitalWrite(GN, HIGH);
}
void r_b()
{
   digitalWrite(R, LOW);digitalWrite(G, HIGH);digitalWrite(B, LOW);digitalWrite(GN, HIGH);
}
void g_b()
{
   digitalWrite(R, HIGH);digitalWrite(G, LOW);digitalWrite(B, LOW);digitalWrite(GN, HIGH);
}

void setup() 
{
  Serial.begin(9600);
  pinMode(R, OUTPUT);pinMode(G, OUTPUT);pinMode(B, OUTPUT);pinMode(GN, OUTPUT);
}

void loop() 
{
  randNumber = random(1,6);
    if( randNumber == 1);{
      red();delay(1500);}
    if( randNumber == 2);{
      green();delay(1500);}
    if( randNumber == 3);{
      blue();delay(1500);}
    if( randNumber == 4);{
      r_g();delay(1500);}
    if( randNumber == 5);{
      r_b();delay(1500);}
    if( randNumber == 6);{
      g_b();delay(1500);}
}
