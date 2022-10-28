const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
Serial.begin(9600); 
}
void loop() {

digitalWrite(trigPin, LOW); //clear trigger pin
delay(2);

digitalWrite(trigPin, HIGH);
delay(10);  // Set trigPin on HIGH state for 10 micro seconds


digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds

distance= duration*0.034/2;

Serial.print("Distance(cm): ");
Serial.println(distance);
}
