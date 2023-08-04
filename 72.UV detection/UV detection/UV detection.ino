?*
Author: Dharmendra Kumar Yadav
*/
#include <Wire.h> 
#include "Adafruit_VEML6075.h"

Adafruit_VEML6075 uv = Adafruit_VEML6075();

void setup() {
  Serial.begin(9600);
  Serial.println("VEML6075 Test");

  if (! uv.begin()) {
    Serial.println("Failed to communicate with VEML6075 sensor.");
  }
  Serial.println("Found the VEML6075 sensor");
}

void loop() {
  Serial.print("UV Index reading: "); Serial.println(uv.readUVI());
  delay(1000);
}