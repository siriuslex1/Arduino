#include "LightControl.h"


int val_light = 0;//读取相应值的一个变量
int change_val = 0;//这个是进行完数字变换的一个变量；

void lightControl(int value){
    
    change_val = value;
    
    if(change_val == 0){
      digitalWrite(lightControlPin,LOW);
      delay(5);
    }
    else{
      analogWrite(lightControlPin,change_val);
      delay(5);
    }
}

int lightVal(){
  return change_val;
}

void lightinit()
{
   pinMode(lightControlPin, OUTPUT);
}
