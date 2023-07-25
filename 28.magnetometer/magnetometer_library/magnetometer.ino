/*

 * GY-273 Compass Module  ->  Arduino
 * VCC  -> VCC  
 * GND  -> GND
 * SCL  -> A5/SCL, 
 * SDA  -> A4/SDA, 
 * DRDY -> Not Connected (in this example)
 * 
 * Voltage Note
 * ~~~~~~~~~~~~  
 * The GY-273 Board has a 3v3 Regulator on it, and the SDA/SCL are pulled up to that so it is OK to 
 * use with 5v Arduino's
 
/* 
 *  Author:dharmendra Kumar Yadav
 
 */


#include <Arduino.h>
#include <Wire.h>
#include <HMC5883L_Simple.h>

// Create a compass
HMC5883L_Simple Compass;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
    
  // Magnetic Declination is the correction applied according to your present location
  // in order to get True North from Magnetic North, it varies from place to place.
  // 
  // The declination for your area can be obtained from http://www.magnetic-declination.com/
  // Take the "Magnetic Declination" line that it gives you in the information, 
  //
  // Examples:
  //   Christchurch, 23° 35' EAST
  //   Wellington  , 22° 14' EAST
  //   Dunedin     , 25° 8'  EAST
  //   Auckland    , 19° 30' EAST
  //    
  Compass.SetDeclination(-0, 23, 'W');  
  
  // The device can operate in SINGLE (default) or CONTINUOUS mode
  //   SINGLE simply means that it takes a reading when you request one
  //   CONTINUOUS means that it is always taking readings
  // for most purposes, SINGLE is what you want.
  Compass.SetSamplingMode(COMPASS_SINGLE);
  
  // The scale can be adjusted to one of several levels, you can probably leave it at the default.
  // Essentially this controls how sensitive the device is.
  //   Options are 088, 130 (default), 190, 250, 400, 470, 560, 810
  // Specify the option as COMPASS_SCALE_xxx
  // Lower values are more sensitive, higher values are less sensitive.
  // The default is probably just fine, it works for me.  If it seems very noisy
  // (jumping around), incrase the scale to a higher one.
  Compass.SetScale(COMPASS_SCALE_130);
  
  // The compass has 3 axes, but two of them must be close to parallel to the earth's surface to read it, 
  // (we do not compensate for tilt, that's a complicated thing) - just like a real compass has a floating 
  // needle you can imagine the digital compass does too.
  //
  // To allow you to mount the compass in different ways you can specify the orientation:
  //   COMPASS_HORIZONTAL_X_NORTH (default), the compass is oriented horizontally, top-side up. when pointing North the X silkscreen arrow will point North
  //   COMPASS_HORIZONTAL_Y_NORTH, top-side up, Y is the needle,when pointing North the Y silkscreen arrow will point North
  //   COMPASS_VERTICAL_X_EAST,    vertically mounted (tall) looking at the top side, when facing North the X silkscreen arrow will point East
  //   COMPASS_VERTICAL_Y_WEST,    vertically mounted (wide) looking at the top side, when facing North the Y silkscreen arrow will point West  
  Compass.SetOrientation(COMPASS_HORIZONTAL_X_NORTH);
  
}

// Our main program loop.
void loop()
{
   float heading = Compass.GetHeadingDegrees();
   
   Serial.print("Heading: \t");
   Serial.println( heading );   
   delay(1000);
}
