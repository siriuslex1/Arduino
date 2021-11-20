/*
 * @Descripttion   
 * @version        
 * @Author         Xiaoqi Lai
 * @Date           2021-07-05 16:26:43
 * @LastEditors    Xiaoqi Lai
 * @LastEditTime   2021-07-05 16:46:42
 */
#include "MyLCD.h"
#include "../dht/MyDHT.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void LCDInit()
{
    lcd.init();      // 初始化LCD
    lcd.backlight(); //设置LCD背景等亮
}

void LCDSetCursor(int col, int row)
{
    lcd.setCursor(col, row);
}

void LCDPrint(String s)
{
    lcd.print(s);
}

void LCDPrintTempurature()
{
    int a = readTemperature();
    LCDPrint("Temp:" + String(a) + "C");
}
void LCDPrintHumidity()
{
    int a = readHumidity();
    LCDPrint("Temp:" + String(a) + "C");
}

void LCDTAndH()
{
    LCDSetCursor(0, 0);
    LCDPrintTempurature();
    LCDSetCursor(0, 1);
    LCDPrintHumidity();
}