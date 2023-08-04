/*
Author:Dharmendra Kumar Yadav
*/
#include <Wire.h>
#include <Adafruit_MLX_Sensor90614.h>
char *Object_Type[]={"Object","Ambient"};

Adafruit_MLX_Sensor90614 MLX_Sensor = Adafruit_MLX_Sensor90614();

void setup() {
  Serial.begin(9600);
  Serial.println("MLX90614 Senso");  
  MLX_Sensor.begin();  
}

void loop() {

  Display_Temperature('A'); //Get Object temperature in Celsius
  Display_Temperature('B'); //Get Ambient temperature in Celsius
  
  Display_Temperature('C'); //Get Object temperature in Keliven
  Display_Temperature('D'); //Get Ambient temperature in Keliven

  
  Display_Temperature('E'); //Get Object temperature in Fahrenheit
  Display_Temperature('F'); //Get Ambient temperature in Fahrenheit
  Serial.println("########");

  delay(2000);

  
}


float Get_Temperature_Sample(char type)
{
    float temp_value;
    float Object_Temperature = MLX_Sensor.readObjectTempC();
    float Ambient_Temperature = MLX_Sensor.readAmbientTempC();
   if(type =='E')
   {
    temp_value = MLX_Sensor.readObjectTempF(); //Fah. Object
   }else if(type =='F')
   {
    temp_value = MLX_Sensor.readAmbientTempF();//Fah Ambient
   }else if(type =='C')
   {
    temp_value = Object_Temperature + 273.15;// Object Kelvin
   }else if(type =='D')
   {
    temp_value = Ambient_Temperature + 273.15;//Ambient Kelvin
   }else if(type =='A')
   {
    temp_value = Object_Temperature;
   }else if(type =='B')
   {
    temp_value = Ambient_Temperature;
   }
   return temp_value;
 
}

void Display_Temperature(char type)
{
  float temp_data =Get_Temperature_Sample(type);

  if(type =='A')
  {
    Serial.print(Object_Type[0]);
    Serial.print(" ");    
    Serial.print(temp_data);
    Serial.print("°");      
    Serial.println("C");
  }else if(type =='B')
  {
    Serial.print(Object_Type[1]);
    Serial.print(" ");     
    Serial.print(temp_data);
    Serial.print("°");      
    Serial.println("C");
  }else if(type =='C')
  {
    Serial.print(Object_Type[0]);
    Serial.print(" ");     
    Serial.print(temp_data);
    Serial.print("°");      
    Serial.println("F");
  }else if(type =='D')
  {
    Serial.print(Object_Type[1]);
    Serial.print(" ");     
    Serial.print(temp_data);
    Serial.print("°");      
    Serial.println("F");
  }

  else if(type =='E')
  {
    Serial.print(Object_Type[0]);
    Serial.print(" ");     
    Serial.print(temp_data);  
    Serial.print("°");       
    Serial.println(" K");
  }  
  else if(type =='F')
  {
    Serial.print(Object_Type[1]);
    Serial.print(" ");     
    Serial.print(temp_data);  
    Serial.print("°");       
    Serial.println(" K");
  }

}
