/* 
   Author:dharmendra Kumar Yadav
 
 */

#include "DHT.h"

DHT dht;

void setup()
{
  Serial.begin(9600);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");

  dht.setup(dht11,2);   /* set pin for data communication */
}

void loop()
{
  delay(dht.getMinimumSamplingPeriod());  /* Delay of amount equal to sampling period */  

  float humidity = dht.getHumidity();     /* Get humidity value */
  float temperature = dht.getTemperature(); /* Get temperature value */

  Serial.print(dht.getStatusString());      /* Print status of communication */
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  Serial.print("\t\t");
  Serial.println(dht.toFahrenheit(temperature), 1); /* Convert temperature to Fahrenheit units */
}
