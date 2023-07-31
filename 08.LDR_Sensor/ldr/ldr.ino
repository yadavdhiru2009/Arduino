/*
Author :Dharmendra Kumar Yadav
*/
int LDR = A0;

void setup() 
{
Serial.begin(9600);
pinMode(LDR, INPUT);
}

void loop() {
int LDRValue = analogRead(LDR);
Serial.print("Light intensity in % = ");
Serial.println(LDRValue/10);
delay(1000);

//if (LDRValue <=700) 
//{
//digitalWrite(LED, HIGH);
//Serial.println("It's Dark Outside; Lights status: ON");
//}
//else 
//{
//digitalWrite(LED, LOW);
//Serial.println("It's Bright Outside; Lights status: OFF");
//}
}
