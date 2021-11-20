#include  <Arduino.h>
#include "MYPINLINE.h"

#ifndef  __MYALARM_H__
#define  __MYALARM_H__
/*//定义警报器相关引脚
#define sensPin A0
#define ledR 4
#define pinBuzzer 3*/

/**
 * @brief   初始化警报器模块
 * @return  -->无
 * 
 */
 void alarminit();

/**
 * @brief   判断是否有人接近
 * @return  -->1表示有人靠近，0表示无人
 */
 int judgePerson();

 /**
  * @brief  对警报系统进行操作
  * @return  -->无
  */
  void useAlarm();

 /**
  * @brief  警报关闭操作
  * @return -->无
  */
  void closeAlarm();

 /**
  * @brief  亮灯操作
  * @return -->无
  */
  void ledLight();

 /**
  * @brief  警报操作
  * @return -->无
  */
  void soundAlarm();


  #endif
