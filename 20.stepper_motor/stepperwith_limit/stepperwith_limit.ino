/* Author:Dharmendra Kumar yadav
 *  in this code the motor move in the x and y 
 *  direction and at there is one switch which give the home position to the motor  
 *  the motor run from the home position to the forward and again come to the home in both  axis
 */
 
 
 //defines pins numbers
const int stepPinY = 3;
const int dirPinY = 4;
const int homeSwitchPinY = 8;
const int stepPinX = 6;
const int dirPinX = 7;
const int homeSwitchPinX = 9;

void setup() {

   Serial.begin(9600);

  // Sets the two pins as Outputs
  pinMode(stepPinX,OUTPUT);
  pinMode(dirPinX,OUTPUT);
  pinMode(homeSwitchPinX , INPUT_PULLUP);
  pinMode(stepPinY,OUTPUT);
  pinMode(dirPinY,OUTPUT);
  pinMode(homeSwitchPinY, INPUT_PULLUP);
  // Set Dir to Home switch
  digitalWrite(dirPinY,HIGH); // Enables the motor to move in a particular direction
  digitalWrite(dirPinX,HIGH);
  homing();

}
void loop()
{
  }
void homing() {

    int homeSwX = digitalRead( homeSwitchPinX);
    int homeSwY = digitalRead( homeSwitchPinY);

    while(( homeSwX == HIGH  ) &&  (homeSwY == HIGH  ))
    {
     
        motorStepX(50);
        motorStepY(50);

    }
    while(( homeSwX == LOW  ) &&  (homeSwY == LOW  ))
    {
          digitalWrite(dirPinX,LOW);
          digitalWrite(dirPinY,LOW);
         delay(1000);
    }
     while(( homeSwX == HIGH  ) &&  (homeSwY == LOW  ))
    {
     
        
        
        motorStepX(50);
         

    }
    while(( homeSwX == LOW  ) &&  (homeSwY == HIGH  ))
    {  
          motorStepY(50);
          
    }

    
    
 
}
void motorStepX( int MAX){

   for(int x = 0; x < MAX; x++) {
        digitalWrite(stepPinX,HIGH);
        delayMicroseconds(50);
        digitalWrite(stepPinX,LOW);
        delayMicroseconds(50);
      }
}
void motorStepY( int MAX){

   for(int x = 0; x < MAX; x++) {
        digitalWrite(stepPinY,HIGH);
        delayMicroseconds(50);
        digitalWrite(stepPinY,LOW);
        delayMicroseconds(50);
      }
}
