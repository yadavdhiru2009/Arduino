/*
Author :Dharmendra kumar yadav
In this code a Digital sound sensor is interface with the Ardiuno 
which detect the Sound and when reach to a thresold led turn on and 
led turn off when it goes below thresold

*/
int ledPin=13;
int sensorPin=7;
boolean val =0;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin (9600);
}
  
void loop (){
  val =digitalRead(sensorPin);
  Serial.println (val);
  // when the sensor detects a signal above the threshold value, LED flashes
  if (val==HIGH) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}
