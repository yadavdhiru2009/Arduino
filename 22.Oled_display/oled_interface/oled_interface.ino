#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "images_oled.h"

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET); /* Object of class Adafruit_SSD1306 */

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); /* Initialize display with address 0x3C */
  display.clearDisplay(); /* Clear display */
  display.setCursor(15,5); /* Set x,y coordinates */
  display.setTextSize(1); /* Select font size of text. Increases with size of argument. */
  display.setTextColor(WHITE); /* Color of text*/
  display.println("ElectronicWings"); /* Text to be displayed */
  display.display();
  delay(500);
  /* Draw rectangle with round edges. Parameters (x_co-ord,y-co-ord,width,height,color) */
  display.drawRoundRect(5, 35, 35, 25, 1, WHITE);
  /* Draw circle. Parameters (x_co-ord of origin,y-co-ord of origin,radius,color) */
  display.drawCircle(65, 50, 12, WHITE);
  /* Draw triangle. Parameters (x0,y0,x1,y1,x2,y2,width,color). (x0,y0), (x1,y1) and (x2,y2) are the co-ord of vertices of the triangle  */
  display.drawTriangle(90, 60, 105, 35, 120, 60, WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  /* Draw image. Parameters (x_co-ord, y_co-ord, name of array containing image, width of image in pixels, height in pixels, color) */
  display.drawBitmap(0, 0, Arduino_Logo, 128, 64, WHITE);
  display.display();
  delay(1000); 
}

void loop() {
  display.clearDisplay();
  display.drawBitmap(0, 0, Smiley_1, 128, 64, WHITE);
  display.display();
  delay(200);
  display.clearDisplay();
  display.drawBitmap(0, 0, Smiley_2, 128, 64, WHITE);
  display.display();
  delay(200);
  display.clearDisplay();
  display.drawBitmap(0, 0, Smiley_3, 128, 64, WHITE);
  display.display();
  delay(200);
  display.clearDisplay();
  display.drawBitmap(0, 0, Smiley_4, 128, 64, WHITE);
  display.display();
  delay(200);
}
