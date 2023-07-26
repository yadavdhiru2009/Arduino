/* 
 *  Author:dharmendra Kumar Yadav
 
 */
const int currentPin = A0;
void setup() {
 
  Serial.begin(9600);
}
 
void loop() {
 
  float average = 0;
  for(int i = 0; i < 100; i++) {
    average = average + (.044 * analogRead(A0) - 3.78) / 1000;//this is 
    //for the 5A mode, if 20A or 30A mode, need to modify this formula to 
    //(.19 * analogRead(A0) -25) for 20A mode and 
    //(.044 * analogRead(A0) -3.78) for 30A mode
    delay(1);
  }
  Serial.println(average);  
}
