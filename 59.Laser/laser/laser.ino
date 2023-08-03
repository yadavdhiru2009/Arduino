/*
Author:Dharmendra Kumar Yadav
*/

int Laser = 2;   
int voltage = 0; 

void setup()

{
Serial.begin(9600); 
pinMode (Laser,OUTPUT); 
digitalWrite(Laser,LOW);  // set laser off at startup or reset
}

void loop() 
{
  digitalWrite(Laser,HIGH);      // turning the laser on
  voltage = analogRead(A0);                                                    //reading the voltage on A0 and storing the value received in "voltage"
  float voltage1 = voltage * (5.0 / 1023.0);                                  // transforming the value stored in "voltage" to readable information
  Serial.print("the laser is ON and the voltage on the center pin is ");      
  Serial.println(voltage1);                                                    
  Serial.println();                                                               
    delay(2000);                                                                // wait for two second 
  digitalWrite(Laser,LOW);                                                    // turning the laser off
  voltage = analogRead(A0);                                                      
  float voltage2 = voltage * (5.0 / 1023.0);                               
  Serial.print("the laser is OFF and the voltage on the center pin is ");          
  Serial.println(voltage2);                                                       
  Serial.println();                                                             
    delay(2000);                                                               // wait for two second 
}