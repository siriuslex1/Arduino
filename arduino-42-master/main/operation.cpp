

#include "operation.h"
#include "MYALARM.h"

String Msg = "";
int flag = 0;
int alarmSwith = 0;//默认一开始按钮是关闭状态
int doorKey = 0;

void operateinit()
{
    LCDSetCursor(0, 0);
    LCDPrint("READY");
}



void changeOperation()
{  
  Msg = "";
  flag = 0;
  while (Serial.available() > 0)
    {
        Msg += char(Serial.read());
        delay(2);
        flag = 1;
    }
    if(flag == 1){
      LCDclearLine1();
      LCDSetCursor(0, 0);
      LCDPrint(Msg);

       if (Msg == "INIT")
       {
          allState();
       }
       
       if (Msg == "TP")
       {
          tpOperation();
       }
       if (Msg[0] == 'x' && Msg[1] == 's')
       {
          spanOperation();
       }
       if (Msg[0] == 'x' && Msg[1] == 'a')//警报点击的返回信号为一个参数1/0（1为开，0为关），前缀为xaa
       {
          alarmSwith = atoi( String(Msg[3]).c_str());
          alarmOperation();
          delay(10);
       }
       if (Msg[0] == 'x' && Msg[1] == 'd')//使用按输入时间转动舵机，最大为十秒，一个参数，前缀xda
       {
          doorTime();
       }
       if (Msg[0] == 'x' && Msg[1] == 'l')//使用输入亮度来控制灯，并显示亮度，三个参数，前缀xlc
       {
          int lightvalue = atoi( (String(Msg[3]) + String(Msg[4]) + String(Msg[5])).c_str());
          lightControl(lightvalue);
          lightOperation();
       }
       if (Msg == "WS")//输入指令来显示窗户状态，一个参数0，前缀xwa
       {
          windowShow();
       }
       if (Msg == "DS")//输入指令来显示门的状态，一个参数0，前缀xea
       {
          doorShow();
       }
       }
       
}

void alarmOperation()
{
  String alarmstate;
  if(alarmSwith == 0){
      alarmstate = "alarm: close";
      LCDclearLine2();
      LCDSetCursor(0, 1);
      LCDPrint(alarmstate);
  }else{
      alarmstate = "alarm: open";
      LCDclearLine2();
      LCDSetCursor(0, 1);
      LCDPrint(alarmstate);
  }
  Serial.println(alarmstate);
}

void doorShow()
{
    
    int doorout = doorState();
    String showdoor;
    if(doorout == 0){
      showdoor = "door: close";
      LCDclearLine2();
      LCDSetCursor(0, 1);
      LCDPrint(showdoor);
    }else{
      showdoor = "door: open";
      LCDclearLine2();
      LCDSetCursor(0, 1);
      LCDPrint(showdoor);
    }
    Serial.println(showdoor);
}

void windowShow()
{
    
    int windowout = windowState();
    String showwindow;
    if(windowout == 0){
     showwindow = "window: close";
     LCDclearLine2();
     LCDSetCursor(0, 1);
     LCDPrint(showwindow);
    }else{
     showwindow = "window: open";
     LCDclearLine2();
     LCDSetCursor(0, 1);
     LCDPrint(showwindow);
    }
    Serial.println(showwindow);
}

void lightOperation()
{
     String lig = "bright:" + String(lightVal());
     LCDclearLine2();
     LCDSetCursor(0, 1);
     LCDPrint(lig + "");
     
     Serial.println(lig);
}


void tpOperation()
{
     String result = "Temp:" + String(readTemperature()) + "C;" + "Hum:" + String(readHumidity()) + "%;";
     LCDclearLine2();
     LCDSetCursor(0, 1);
     LCDPrint(result);
     Serial.println(result);
}


void spanOperation()
{
      int angle = atoi( (String(Msg[3]) + String(Msg[4])).c_str());
      doorMove(angle);
      String result = String("Door spin") + String(angle);
      LCDclearLine2();
      LCDSetCursor(0, 1);
      LCDPrint(result);
      Serial.println(result);
}


void alarmUse()
{
    if(alarmSwith == 1){
          useAlarm();
       }else{
          closeAlarm();
       }
}

void doorTime()
{
     int doortime = atoi( String(Msg[3]).c_str());
     if(doorKey = 0){
     doorKey = 1;
     autoDoor(doorKey,doortime);
     }else{
     doorKey = 0;
     autoDoor(doorKey,doortime);
     }
     String result = String("Door spin") + String(doortime);
     LCDclearLine2();
     LCDSetCursor(0, 1);
     LCDPrint(result);
     Serial.println(result + "s");
}



void allState()
{
    String tandh = "Temp:" + String(readTemperature()) + "C;" + "Hum:" + String(readHumidity()) + "%";
    String alarmstate;
    String showdoor;
    String showwindow;
    int doorout = doorState();
    int windowout = windowState();
    
    if(windowout == 0){
     showwindow = "window: close";
    }else{
     showwindow = "window: open";
    }
    
    if(alarmSwith == 0){
      alarmstate = "alarm: close";
  }else{
      alarmstate = "alarm: open";
  }

    if(doorout == 0){
      showdoor = "door: close";
    }else{
      showdoor = "door: open";
    }

    Serial.print(tandh + "?");
    Serial.print(alarmstate + "?");
    Serial.print(showdoor + "?");
    Serial.print(showwindow + "?");
}
