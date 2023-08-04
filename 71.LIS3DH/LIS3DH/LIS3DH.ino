/*
Author:Dharmendra Kumar Yadav
*/
#include <Wire.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

Adafruit_LIS3DH lis = Adafruit_LIS3DH();

void setup(void) {
  Serial.begin(115200);
  while (!Serial) delay(10);    

  Serial.println("LIS3DH test!");

  if (! lis.begin(0x19)) {  
    Serial.println("Couldnt start");
    while (1) yield();
  }
  Serial.println("LIS3DH found!");

  lis.setRange(LIS3DH_RANGE_16_G);   // 2, 4, 8 or 16 G!
}

void loop() {

  //Accelerometer Readings
  lis.read();      // get X Y and Z data at once
  sensors_event_t event;
  lis.getEvent(&event);

  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("| X: "); Serial.print(event.acceleration.x);
  Serial.print("  Y: "); Serial.print(event.acceleration.y);
  Serial.print("  Z: "); Serial.print(event.acceleration.z);
  Serial.println(" m/s^2 ");

  //ADC Readings
  int16_t adc;
  uint16_t volt;

  adc = lis.readADC(1);
  volt = map(adc, -32512, 32512, 1800, 900);
  Serial.print("ADC1:\t"); Serial.print(volt); Serial.print(" mV  "); 
  
  adc = lis.readADC(2);
  volt = map(adc, -32512, 32512, 1800, 900);
  Serial.print("ADC2:\t"); Serial.print(volt); Serial.print(" mV  ");  

  adc = lis.readADC(3);
  volt = map(adc, -32512, 32512, 1800, 900);
  Serial.print("ADC3:\t"); Serial.print(volt); Serial.print(" mV  "); 

  delay(200);
}