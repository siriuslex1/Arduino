
#include "MYALARM.h"



int sensValue = 0;


void alarminit()
{
  pinMode(sensPin, INPUT);
  pinMode(ledR, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
}


int judgePerson()
{
  sensValue = analogRead(sensPin);
  if(sensValue > 300){
    return 1;
  }else{
    return 0;
  }
}

void useAlarm()
{
  if(judgePerson() == 1){
    ledLight();
    soundAlarm();
    delay(30);
  }else{
    closeAlarm();
  }
  
}
void closeAlarm()
{
  digitalWrite(ledR,LOW);
  digitalWrite(pinBuzzer,LOW);
}

void ledLight()
{
  digitalWrite(ledR,HIGH);
}

void soundAlarm()
{
  digitalWrite(pinBuzzer,HIGH);
}
