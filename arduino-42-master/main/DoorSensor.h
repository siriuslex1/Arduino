#ifndef __DOORSENSOR_H__
#define __DOORSENSOR_H__

// 引入库函数
#include <Arduino.h>
#include "MYPINLINE.h"

/*// 定义DHT引脚
#define doorSensorPin 7
#define doorLightPin 2*/

/**
 * @brief    使用电位器控制光的亮度
 */
void doorSensor();

/**
 * @brief    返回门的开关状态，0为门关，1为门开
 */
int doorState();

/**
 * @brief    doorSensor的初始化函数
 * @return    --> 无
 */
void doorSinit();



#endif
