/*
Arduino Input Capture (Frequency Measurement)
* Author: Dharmendra Kumar Yadav
*/
#include <LiquidCrystal.h>
 
bool MeasEnd = 0;
uint16_t T1OVF_Counter = 0;
unsigned long T1 = 0, T2 = 0, T = 0, Freq = 0;
LiquidCrystal MyLCD(12, 11, 5, 4, 3, 2); // Creates an LCD object, Parameters: (RS, EN, D4, D5, D6, D7)
 
ISR(TIMER1_OVF_vect)
{
  T1OVF_Counter++;
}
 
ISR(TIMER1_CAPT_vect)
{
  if(!MeasEnd)
  {
    T1 = ICR1;
    MeasEnd = 1;
  }
  else
  {
    T2 = ICR1;
    if(T1OVF_Counter)
    {
      T = T2 + (65536 * T1OVF_Counter) - T1;
    }
    else
    {
      T = T2 - T1;
    }
    if(T == 0)
    {
      Freq = 0;
    }
    else
    {
      Freq = (2000000/T);
    }
    T1OVF_Counter = 0;
    MeasEnd = 0;
  }
}
 
void setup()
{
  TCCR1A = 0;           // Init Timer1A
  TCCR1B = 0;           // Init Timer1B
  TCCR1B |= B11000010;  // Internal Clock, Prescaler = 8, ICU Filter EN, ICU Pin RISING
  TIMSK1 |= B00100001;  // Enable Timer OVF & CAPT Interrupts
  MyLCD.begin(16, 2); // Set up the number of columns and rows on the LCD.
}
 
void loop()
{
  MyLCD.clear();
  MyLCD.setCursor(0, 0);
  MyLCD.print("Frequency:");
  MyLCD.setCursor(0, 1);
  MyLCD.print(Freq);
  delay(50);
}