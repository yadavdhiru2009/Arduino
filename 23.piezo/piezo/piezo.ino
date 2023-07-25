/* 
 *  Author:dharmendra Kumar Yadav
 
 */
#define DRUM1 0  // piezo at analog pin
#define THRESHOLD 100
int R1=5; //buzzer1
int R2=6; // buzzer 2

byte val = 0;

void setup()
{
  Serial.begin(9600);
  pinMode (R1,OUTPUT);
  pinMode (R2,OUTPUT);
}

void loop()
{
  val = analogRead(DRUM1);

  if(val > THRESHOLD)
  { 
    digitalWrite(R1,HIGH);
    delay(500);
    digitalWrite(R1,LOW);
    Serial.println("hard");
  }
  else if(val > 200) 
  {
    digitalWrite(R2,HIGH);
    delay(500);
    digitalWrite(R2,LOW);
    Serial.println("soft");
    
    }
 
}
