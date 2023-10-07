/*
*Arduino Motor Optical Encoder RPM Measurement
* Author:Dharmendra Kumar Yadav
* 
*/
#define ENCODER_PIN 2
#define ENCODER_N   20
unsigned long T1 = 0, T2 = 0, T;
bool MeasDone = 0;
int Motor_RPM = 0;
void INT0_ISR(void)
{
  if(MeasDone)
  {
    T2 = micros();
    T = T2 - T1;
    MeasDone = 0;
  }
  else
  {
    T1 = micros();
    MeasDone = 1;
  }
}
void setup()
{
  Serial.begin(9600);
  pinMode(ENCODER_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN), INT0_ISR, RISING);
}
void loop()
{
  Motor_RPM = (60000000) / (T * ENCODER_N);
  Serial.print("Motor RPM: ");
  Serial.println(Motor_RPM);
  delay(250);
}