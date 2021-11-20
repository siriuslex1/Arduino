#ifndef __LIGHTCONTROL_H__
#define __LIGHTCONTROL_H__

// 引入库函数
#include <Arduino.h>
#include "MYPINLINE.h"

// 定义灯控引脚
//#define lightControlPin 6

/**
 * @brief    使用电位器控制光的亮度
 * @return  -->无
 * @param   value int -->输入的亮度值
 */
void lightControl(int value);
/**
 * @brief    返回当前的光亮值
 * @return    --> 无
 */
int lightVal();

/**
 * @brief    lightControl的初始化函数
 * @return    --> 无
 */
void lightinit();

#endif
