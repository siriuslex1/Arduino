
#ifndef __LIGHTSENSOR_H__
#define __LIGHTSENSOR_H__

// 引入库函数
#include <Arduino.h>
#include <Servo.h>
#include "MYPINLINE.h"

// 定义感应灯引脚
//#define lSensorPin 5
//#define ligsen A1

/**
 * @brief    使舵机旋转特定角度
 */
void light();


void lightSensorinit();


#endif
