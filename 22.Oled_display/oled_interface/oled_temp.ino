/*********************************************************************
This is an example for our Monochrome OLEDs based on SSD1306 drivers

/* 
 *  Author:dharmendra Kumar Yadav
 


This example is for a 128x64 size display using I2C to communicate
3 pins are required to interface (2 I2C and one reset)

*********************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"

#define DHTTYPE DHT11   // DHT 11
#define DHTPIN 2

DHT dht(DHTPIN, DHTTYPE);


#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);




#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup()   {                
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  }


void loop() {  
  display.display(); //I love Adafruit :D
  delay(1000);
  
  display.clearDisplay();   // Clear the buffer.

  float h = dht.readHumidity();  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) { // Check if any reads failed and exit early (to try again).
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t\n");
  
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("SIC");
  display.setCursor(60,0);
  display.println((int)t);
  display.setTextSize(1);
  display.setCursor(100,0);
  display.println("o");
  display.setTextSize(2);
  display.setCursor(110,0);
  display.println("C");

  display.setTextSize(3);
  display.setCursor(0,30);
  display.println("NEM%");
  display.setCursor(80,30);
  display.println((int)h);

  display.display();
  delay(3000);
  display.clearDisplay();
 
}
