/* 
 *  Author:dharmendra Kumar Yadav
 
 */
int ThermistorPin = 0;
int Vo;
float R1 = 2500;
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
Serial.begin(9600);
}

void loop() {

  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
  T = (T * 9.0)/ 5.0 + 32.0; 
 float C=((T-32)*1.8);

  Serial.print("Temperature: "); 
  Serial.print(C);
  Serial.println(" C"); 

  delay(500);
}
