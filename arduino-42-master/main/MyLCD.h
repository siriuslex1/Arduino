/*
 * @Descripttion   
 * @version        
 * @Author         Xiaoqi Lai
 * @Date           2021-07-05 16:25:11
 * @LastEditors    Xiaoqi Lai
 * @LastEditTime   2021-07-05 16:47:49
 */
#ifndef __MYLCD_H__
#define __MYLCD_H__

#include <Wire.h>
#include "LiquidCrystal_I2C.h"

// lcd 默认连接A4,A5引脚

/**
 * @brief    LCD初始化函数
 * @return    --> 无
 */
void LCDInit();

/**
 * @brief    LCD设置指针点
 * @return    --> 无
 * @param    col int --> 指针列
 * @param    row int --> 指针行
 */
void LCDSetCursor(int col, int row);

/**
 * @brief    LCD输出字符函数
 * @return    --> 无
 * @param    s String --> 输出的字符
 */
void LCDPrint(String s);

/**
 * @brief    LCD 打印温度和湿度
 * @return    --> 无
 */
void LCDTAndH();

/**
 * @brief   清空LCD第一行
 * @return    --> 无
 */
void LCDclearLine1();


/**
 * @brief   清空LCD第二行
 * @return    --> 无
 */
void LCDclearLine2();


#endif
