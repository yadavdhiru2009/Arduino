/*
 * Author:Dharmendra Kumar Yadav
  Let the motors run!
  Turns on an Motor on for Two second, then off for one second, repeatedly.
 
 */
 
// Pin 13 has an LED, also connected Motor.
// give it a name:
int motor = 13;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(motor, OUTPUT);     
}
// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(motor, HIGH);   // turn the Motor on (HIGH is the voltage level)
  delay(2000);               // wait for Two second
  digitalWrite(motor, LOW);    // turn the Motor off by making the voltage LOW
  delay(1000); 
}       
