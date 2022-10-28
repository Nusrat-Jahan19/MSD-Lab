
#include<LiquidCrystal.h>

int ldr=A4;
int buzzer = 7;
int RS=8,EN=9,D4=10,D5=11,D6=12,D7=13;
int value=0;
LiquidCrystal lcd (RS,EN,D4,D5,D6,D7);

void setup() {
  
  pinMode(buzzer,OUTPUT);
  lcd.begin(16,2);
  lcd.print("Initializing...");
  delay(1000);
  lcd.clear();
}

void loop() {
  value=analogRead(ldr);
  if(value>300)
  {
    lcd.setCursor(0,0);
    lcd.print("Light is ON");
    noTone(buzzer);
    delay(500);
  }

  else if(value<300)
  {
    lcd.setCursor(0,0);
    lcd.print("Light is OFF");
    tone(buzzer,1000);
    delay(500);
    lcd.clear();
  }

}
