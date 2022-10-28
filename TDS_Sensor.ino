

#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);



int sensorValue = 0;
float tdsValue = 0;
float Voltage = 0;

void setup() {

  lcd.begin(16, 2);
  pinMode(A1, INPUT);
}

void loop() {
  sensorValue = analogRead(A1);
  Voltage = sensorValue * 5 / 1024.0; //Convert analog reading to Voltage
  tdsValue = (133.42 * Voltage * Voltage * Voltage - 255.86 * Voltage * Voltage + 857.39 * Voltage) * 0.5; //Convert voltage value to TDS value
  lcd.setCursor(0, 0);
  lcd.print("TDS Value = ");
  lcd.print(tdsValue);
  lcd.println(" ppm");
  delay(1000);
}
