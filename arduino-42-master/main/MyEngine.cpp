/*
 * @Descripttion   
 * @version        
 * @Author        
 * @Date           2021-07-06
 * @LastEditors    
 * @LastEditTime   2021-07-06
 */
#include "MyEngine.h"


Servo servo_pin_13;
int angleD = 90;
int j;
int angleDoor = servo_pin_13.read();

void doorMove(int angle)
{
    static int num = 0;
    int count;
    bool t = false;
    
    angleD = angle;
    

             for(j=0;j<angle;j++){
                servo_pin_13.write(j);
                delay(1);
             }

            delay(10000);
            for(j=angle;j>0;j--){
                servo_pin_13.write(j);
                delay(1);
             }

}
void autoDoor(int key){

     if(key == 1){
       delay(10);
       for(j=angleDoor;j<90;j++){
                servo_pin_13.write(j);
                delay(1);
             }
     }        
   else
        {    for(j=angleDoor;j>0;j--){
                servo_pin_13.write(j);
                delay(1);
        }
          }             
}
//speed is the speed of the door
void autoDoor(int key,int speed){
     if(key == 1){
       delay(10);
       for(j=angleDoor;j<90;j++){
                servo_pin_13.write(j);
                delay(speed/(90-angleDoor)*1000);
             }
     }        
   else
        {    for(j=angleDoor;j>0;j--){
                servo_pin_13.write(j);
                delay(speed/angleDoor*1000);
        }
          }             
}


void Doorinit()
{
  servo_pin_13.attach(engine);
  servo_pin_13.write(0);

}
