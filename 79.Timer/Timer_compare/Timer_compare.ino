/*
Arduino Timer Compare Match Interrupt
* Author:Dharmendra Kumar Yadav
*/
 
ISR(TIMER1_COMPA_vect)
{
  OCR1A += 25000; // Advance The COMPA Register
  // Handle The 100ms Timer Interrupt
  //...
}
 
void setup()
{
  TCCR1A = 0;           // Init Timer1
  TCCR1B = 0;           // Init Timer1
  TCCR1B |= B00000011;  // Prescalar = 64
  OCR1A = 25000;        // Timer CompareA Register
  TIMSK1 |= B00000010;  // Enable Timer COMPA Interrupt
}
void loop()
{
  // Do Nothing
}
