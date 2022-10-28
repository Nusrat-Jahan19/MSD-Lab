
int LeftMotorForward = 7; // Pin 7 has Left Motor connected on Arduino boards.
int LeftMotorReverse = 6; // Pin 6 has Left Motor connected on Arduino boards.

void setup()
{
  Serial.begin(9600);
  pinMode(LeftMotorForward, OUTPUT);  
  pinMode(LeftMotorReverse, OUTPUT);  
}
void loop() {
   // Forward
   
   digitalWrite(LeftMotorForward, HIGH);
   digitalWrite(LeftMotorReverse, LOW);  
   delay(2000);
   
   // Reverse
   digitalWrite(LeftMotorReverse, HIGH);   
   digitalWrite(LeftMotorForward, LOW);  
   delay(2000);
   
   // Stop
   digitalWrite(LeftMotorReverse, LOW);  
   digitalWrite(LeftMotorForward, LOW);   
   delay(2000);
}

