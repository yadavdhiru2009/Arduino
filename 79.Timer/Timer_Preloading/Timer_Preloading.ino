/*
* Arduino Timer Preloading
* Author:Dharmendra Kumar Yadav
*/
 
ISR(TIMER1_OVF_vect)
{
  TCNT1 = 40535; // Timer Preloading
  // Handle The 100ms Timer Interrupt
  //...
}
 
void setup()
{
  TCCR1A = 0;           // Init Timer1
  TCCR1B = 0;           // Init Timer1
  TCCR1B |= B00000011;  // Prescalar = 64
  TCNT1 = 40535;        // Timer Preloading
  TIMSK1 |= B00000001;  // Enable Timer Overflow Interrupt
}
void loop()
{
  // Do Nothing
}
