/*
Arduino Timer (Counter Mode)
* Author: Dharmendra Kumar Yadav
*/
 
void setup()
{
  TCCR1A = 0;           // Init Timer1A
  TCCR1B = 0;           // Init Timer1B
  TCCR1B |= B00000111;  // External Clock on T1 Pin (RISING)
  TCNT1 = 0;
  Serial.begin(9600);
}
 
void loop()
{
  Serial.print("Counter Ticks = ");
  Serial.println(TCNT1);
  delay(250);
}