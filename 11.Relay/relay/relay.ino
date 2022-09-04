    /*
     * Author:Dharmendra kumar yadav
      Can we turn on the bulb? with Relay
      Turns on an Relay on for one second, then off for one second, repeatedly.
      */
     
    // Pin 10 has an Relay connected .
   
    int Relay = 10;
    // the setup routine runs once when you press reset:
    void setup() {                
      // initialize the digital pin as an output.
      pinMode(Relay, OUTPUT);     
    }
    // the loop routine runs over and over again forever:
    void loop() {
      digitalWrite(Relay, HIGH);   // turn the Relay on (HIGH is the voltage level)
      delay(1000);               // wait for a second
      digitalWrite(Relay, LOW);    // turn the Relay off by making the voltage LOW
      delay(1000);               // wait for a second
    }
