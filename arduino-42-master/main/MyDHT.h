/*
 * @Descripttion   
 * @version        
 * @Author         Xiaoqi Lai
 * @Date           2021-07-05 14:20:53
 * @LastEditors    Xiaoqi Lai
 * @LastEditTime   2021-07-05 16:37:40
 */
#ifndef __MYDHT_H__
#define __MYDHT_H__

// 引入库函数
#include "dht11.h"
#include "MYPINLINE.h"

// 定义DHT引脚
//#define dht11Pin 8

/**
 * @brief    读取温度函数
 * @return   int --> 浮点型温度
 */
int readTemperature();

/**
 * @brief    读取湿度函数
 * @return   float --> 浮点型湿度
 */
int readHumidity();

/**
 * @brief    DHT初始化函数
 * @return    --> 无
 */
void DHTinit();

#endif
