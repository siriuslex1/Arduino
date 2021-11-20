/*
 * @Descripttion   
 * @version        
 * @Author         Xiaoqi Lai
 * @Date           2021-07-05 16:18:50
 * @LastEditors    Xiaoqi Lai
 * @LastEditTime   2021-07-05 16:37:55
 */
#include "MyDHT.h"

dht11 d;

int readTemperature()
{
  int total = d.read(dht11Pin);
  return (int)d.temperature;
}

int readHumidity()
{
  int total = d.read(dht11Pin);
  return (int)d.humidity;
}

void DHTinit()
{

  pinMode(dht11Pin, OUTPUT);
}
