


#ifndef __OPERATION_H__
#define __OPERATION_H__

#include "MyLCD.h"
#include "MyDHT.h"
#include "MyEngine.h"
#include "MYALARM.h"
#include "LightControl.h"
#include "WindowSensor.h"
#include "DoorSensor.h"

/**
 * @brief   初始化显示
 * @return  -->无
 * 
 */
 void operateinit();

/**
 *  @brief   改变操作并执行（放在loop中）
 *  @return   -->无
 * 
 */
 void changeOperation();


/**
 *  @brief  打开关闭报警开关（changeOperation执行）
 *  @return -->无
 *  
 */
 void alarmOperation();


/**
 *  @brief  执行温湿度打印操作（changeOperation执行）
 *  @return  -->无
 * 
 */
 void tpOperation();

/**
 *  @brief  执行转动舵机操作（changeOperation执行）
 *  @return -->无
 *  
 */
 void spanOperation();

/**
 *  @brief  执行警报开关的操作（changeOperation执行）
 *  @return -->无
 *  
 */
 void alarmUse();

/**
 *  @brief  执行指定速度开门的操作（changeOperation执行）
 *  @return -->无
 *  
 */
 void doorTime();

/**
 *  @brief  显示门状态（changeOperation执行）
 *  @return -->无
 *  
 */
 void doorShow();

/**
 *  @brief  显示窗户状态（changeOperation执行）
 *  @return -->无
 *  
 */
 void windowShow();

/**
 *  @brief  调整灯的亮度（changeOperation执行）
 *  @return -->无
 *  
 */
 void lightOperation();

/**
 *  @brief  显示初始状态（changeOperation执行）
 *  @return -->无
 *  
 */
 void allState();

 #endif
