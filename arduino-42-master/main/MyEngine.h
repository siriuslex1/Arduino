  
#ifndef __MYENGINE_H__
#define __MYENGINE_H__

// 引入库函数
#include <Arduino.h>
#include <Servo.h>
#include "MYPINLINE.h"

//#define engine 13

/**
 * @brief    使舵机旋转特定角度
 */
void doorMove(int angle);

void autoDoor(int key);

void autoDoor(int key,int speed);

void Doorinit();

#endif
