/* 
 *  Author:dharmendra Kumar Yadav
 
 */

int ledOpen=13;
int switchReed=2;

void setup(){
  pinMode(ledOpen, OUTPUT);
  pinMode(switchReed, INPUT);
  Serial.begin(9600);
}

void loop(){
  
  if (digitalRead(switchReed)==HIGH){
    digitalWrite(ledOpen, LOW);
    Serial.println("Your Door is Close");
  }
  else {
    digitalWrite(ledOpen, HIGH);
    Serial.println("Your Door is Open");
  }
  delay(1);
}