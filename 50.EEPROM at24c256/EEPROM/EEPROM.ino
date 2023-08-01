/*
Author:Dharmendra Kumar YAdav
*/
#include <Wire.h>

#define EEPROM_I2C_ADDRESS_0 0x50
#define EEPROM_I2C_ADDRESS_1 0x51

int EEPROM_I2C_ADDRESS = NULL;
int i=0;
void setup()
{
  Wire.begin();
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  
  for(i=0;i<94;i++)
  {
    if(i<256)
    {
      EEPROM_I2C_ADDRESS = 0x50;
      writeAT24(i, 33+i);
    }
    else
    {
      EEPROM_I2C_ADDRESS = 0x51;
      writeAT24(i-256, 0);
    }
  }
  delay(1000);
  Serial.println("Data from EEPROM");
  Serial.println("-----------------");
  for(i=0;i<94;i++)
  {
    if(i<256)
    {
      EEPROM_I2C_ADDRESS = 0x50;
      Serial.println((char)readAT24(i));
    }
    else
    {
      EEPROM_I2C_ADDRESS = 0x51;
      Serial.println((char)readAT24(i-256));
    }
    
  }
  delay(1000);
  while(1)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
  }

}


// Function to write to EEPROOM
void writeAT24(byte dataAddress, byte dataVal)
{
  Wire.beginTransmission(EEPROM_I2C_ADDRESS);

  Wire.write(dataAddress);
  Wire.write(dataVal);
  Wire.endTransmission();

  delay(5);
}

// Function to read from EEPROM
byte readAT24(byte dataAddress)
{
  byte readData = NULL;
  Wire.beginTransmission(EEPROM_I2C_ADDRESS);
  Wire.write(dataAddress);
  Wire.endTransmission();

  delay(5);
  Wire.requestFrom(EEPROM_I2C_ADDRESS, 1);
  //delay(1);

  if(Wire.available())
  {
    readData =  Wire.read();
  }

  return readData;
}