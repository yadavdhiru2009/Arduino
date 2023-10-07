/*
*Author:Dharmendra Kumar Yadav
TIP120 Connection with Arduino And running 12 Volts dc Motor
*/
#define MOTOR_PWM_PIN 3
 
void setup()
{
  pinMode(MOTOR_PWM_PIN, OUTPUT);
}
 
void loop()
{
  analogWrite(MOTOR_PWM_PIN, (analogRead(A0)>>2));
}