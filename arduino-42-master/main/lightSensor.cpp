#include "lightSensor.h"

void light(){
    int sensor_value = analogRead(ligsen);
    int light_value = map(sensor_value, 0, 700, 0, 255);
    //Serial.println(light_value);
    if (sensor_value < 300)// the point at which the state of LEDs change
    {
         light_value = 255 - light_value;
         analogWrite(lSensorPin, light_value); 
    }
    else
    {
         analogWrite(lSensorPin,LOW); //Sets LEDs OFF
    } 
  }


void lightSensorinit(){
     pinMode(lSensorPin, OUTPUT); 
}
