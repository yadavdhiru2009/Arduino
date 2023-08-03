/*
Author:Dharmendra Kumar Yadav
*/
int sensor_pin = A2;     
int sensor_value;     
 
void setup(void) {
  Serial.begin(9600);   
}
 
void loop(void) {
  sensor_value = analogRead(sensor_pin);  
 
  Serial.print("Analog reading = ");
  Serial.print(sensor_value);     
 
  if (sensor_value < 10) {
    Serial.println(": No pressure");
  } else if (sensor_value < 200) {
    Serial.println(": Light touch");
  } else if (sensor_value < 500) {
    Serial.println(": Light squeeze");
  } else if (sensor_value < 800) {
    Serial.println(": Medium squeeze");
  } else {
    Serial.println(": Strong squeeze");
  }
  delay(1000);
}
