/*
 * @Descripttion   
 * @version        
 * @Author         Xiaoqi Lai
 * @Date           2021-07-05 16:38:11
 * @LastEditors    Xiaoqi Lai
 * @LastEditTime   2021-07-05 16:53:05
 */

#include "MyLCD.h"
#include "MyDHT.h"
#include "MyEngine.h"
#include "MYALARM.h"
#include "LightControl.h"
#include "WindowSensor.h"
#include "DoorSensor.h"
#include "lightSensor.h"
#include "operation.h"
#include "MYPINLINE.h"

void setup()
{
  Serial.begin(9600);
    DHTinit();
    LCDInit();
    Doorinit();
    alarminit();
    lightinit();
    windowinit();
    doorSinit();
    lightSensorinit();
    operateinit();
    
}

void loop()
{
   changeOperation();
   light();
   doorSensor();
   windowSensor();
   alarmUse();
}
