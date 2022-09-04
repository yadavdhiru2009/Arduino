    /*
     * Author:Dharmendra kumar yadav
     Display colors with RGB LED
      Turns on an LED RED,GREEN and BLUE, repeatedly.
      */
     
    // Pin 11,12,13 has an LED connected Through resistor.
    // LED Anode is connected to +5V.
    // give it a name:
    int led = 13;
    int led1 = 12;
    int led2 = 11;
    // the setup routine runs once when you press reset:
    void setup() {                
      // initialize the digital pin as an output.
    pinMode(led, OUTPUT);   //define pin mode as output
    pinMode(led1, OUTPUT); //define pin mode as output
    pinMode(led2, OUTPUT); //define pin mode as output
    }
     
    void loop() {
      digitalWrite(led2, HIGH); //making led pin high
      digitalWrite(led1, HIGH); 
      digitalWrite(led, HIGH);   
      delay(500); 
      digitalWrite(led, LOW);  
      digitalWrite(led1, HIGH); 
      delay(500); 
      digitalWrite(led1, LOW); 
      digitalWrite(led2, HIGH);
      delay(500);  
      digitalWrite(led2 , LOW);    
      delay(500);
    }
