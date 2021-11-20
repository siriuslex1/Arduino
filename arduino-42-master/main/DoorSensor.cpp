#include "DoorSensor.h"


//0 refers to close, 1 refers to open.
void doorSensor(){
  if(digitalRead(doorSensorPin)){
   digitalWrite(doorLightPin,HIGH);
  }
  else{
    digitalWrite(doorLightPin,LOW);
  }
  delay(doorLightPin);
}

int doorState(){
  return digitalRead(doorSensorPin);
}

void doorSinit()
{
  pinMode(doorSensorPin,INPUT);
  pinMode(doorLightPin,OUTPUT);
  digitalWrite(doorLightPin,HIGH);
}
