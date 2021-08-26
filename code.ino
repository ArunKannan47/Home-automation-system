#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

SoftwareSerial mySerial(10, 11); // RX, TX
LiquidCrystal LCD(2,3,4,5,6,7);

#define FAN  8
#define BULB 9

String inputString="";
boolean stringComplete = false;
int sequence = 0;
char inchar = 0;

void setup() 
{
  Serial.begin(9600);
  mySerial.begin(9600);
  inputString.reserve(200);
  pinMode(FAN,OUTPUT);
  pinMode(BULB,OUTPUT);
  digitalWrite(FAN,LOW);
  digitalWrite(BULB,LOW);
  LCD.begin(16,2);
  LCD.setCursor(1,0);
  LCD.print("   BCI HOME     ");  
}

void loop()
{
  if (Serial.available())
  {
      inchar = Serial.read();
      if(inchar == 'A')
      {
          LCD.setCursor(1,1);
          LCD.print(" FAN   : ON    ");  
          digitalWrite(FAN,HIGH);
      }

      else if(inchar == 'B')
      {
          LCD.setCursor(1,1);
          LCD.print(" FAN   : OFF    ");  
          digitalWrite(FAN,LOW);
      }

      else if(inchar == 'C')
      {
          LCD.setCursor(1,1);
          LCD.print(" BULB  : ON    ");  
          digitalWrite(BULB,HIGH);
      }

      else if(inchar == 'D')
      {
          LCD.setCursor(1,1);
          LCD.print(" BULB  : OFF   ");  
          digitalWrite(BULB,LOW);
      }                   
   }
}
