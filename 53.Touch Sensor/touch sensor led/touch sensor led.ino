/*
 Author:Dharmendra Kumar Yadav

*/

void setup()
{ 
  pinMode(8, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  // Turn builtin LED off
  digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{
 
  if(digitalRead(8) == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  delay(100);
}
