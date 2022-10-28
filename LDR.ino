int ldr=A4;
int value = 0;
void setup() {
Serial.begin(9600);
}
void loop() {
  value= analogRead(ldr);
  Serial.println("Intensity of the LDR is =");
  Serial.println(value);
  delay(1000);
}
