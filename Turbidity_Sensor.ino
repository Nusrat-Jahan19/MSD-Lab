
#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
 
int Turbidity_Sensor_Pin = A2;
float Turbidity_Sensor_Voltage;
int samples = 600;
float ntu; // Nephelometric Turbidity Units
 
 
void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600); // for debugging purposes
  pinMode(Turbidity_Sensor_Pin, INPUT);
   
  lcd.home();  
}
 
void loop()
{
    
    Turbidity_Sensor_Voltage = 0;
    /* its good to take some samples and take the average value. This can be quite handy 
     *  in situations when the values fluctuates a bit. This way you can take the average value
     *  i am going to take 600 samples
     */
    for(int i=0; i<samples; i++)
    {
        Turbidity_Sensor_Voltage += ((float)analogRead(Turbidity_Sensor_Pin)/1023)*5;
    }
    
    Turbidity_Sensor_Voltage = Turbidity_Sensor_Voltage/samples;
    // uncomment the following two statments to check the voltage. 
    // if you see any variations, take necessary steps to correct them
    // once you are satisfied with the voltage value then again you can comment these lines
    
    //Serial.println("Voltage:");
    //Serial.println(Turbidity_Sensor_Voltage);
     
    Turbidity_Sensor_Voltage = round_to_dp(Turbidity_Sensor_Voltage,2);
    if(Turbidity_Sensor_Voltage < 2.5){
      ntu = 3000;
    }else{
      ntu = -1120.4*square(Turbidity_Sensor_Voltage)+ 5742.3*Turbidity_Sensor_Voltage - 4352.9; 
    }
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(Turbidity_Sensor_Voltage);
    lcd.print(" V");
 
    lcd.setCursor(0,1);
    lcd.print(ntu);
    lcd.print(" NTU");
    delay(10);
}
 
float round_to_dp( float in_value, int decimal_place )
{
  float multiplier = powf( 10.0f, decimal_place );
  in_value = roundf( in_value * multiplier ) / multiplier;
  return in_value;
}
