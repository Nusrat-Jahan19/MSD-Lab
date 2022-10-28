#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
#define ledpinred  14
#define ledpingreen  15
#define ledpinblue  16


void setup() {
  lcd.begin(16,2);
  pinMode(A1,INPUT);
  pinMode(ledpinred,OUTPUT);
  pinMode(ledpingreen,OUTPUT);
  pinMode(ledpinblue,OUTPUT);
}

void loop() {
  float val = analogRead(A1);
  val = val/1023;
  val = val*14;
  lcd.setCursor(0,0);
  lcd.print(val);
  delay(1000);

  if(val>7)
 {
       digitalWrite(ledpinblue,HIGH);
          delay(1000);
          digitalWrite(ledpingreen,LOW);
          delay(1000);
          digitalWrite(ledpinred,LOW);
          delay(1000);
 }
 
  else if(val==7)
 {
   digitalWrite(ledpinblue,LOW);
          delay(1000);
          digitalWrite(ledpingreen,HIGH);
          delay(1000);
          digitalWrite(ledpinred,LOW);
          delay(1000);
 }
 
 else if(val<7)
 {
         digitalWrite(ledpinblue,LOW);
          delay(1000);
          digitalWrite(ledpingreen,LOW);
          delay(1000);
          digitalWrite(ledpinred,HIGH);
          delay(1000);
 }
  
}
