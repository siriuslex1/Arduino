#include <Servo.h>

Servo servo_pin_3;
Servo servo_pin_8;
Servo servo_pin_4;
Servo servo_pin_7;
Servo servo_pin_11;
//Servo servo_pin_12;

void setup()
{
  servo_pin_3.attach(3);
  servo_pin_8.attach(8);
  servo_pin_4.attach(4);
  servo_pin_7.attach(7);
  servo_pin_11.attach(11);
//  servo_pin_12.attach(12);
}
int a = 25;
int b = 125;
bool first = true;

void loop()
{
 if (first) {
    servo_pin_3.write(90);
    servo_pin_8.write(85);
    servo_pin_4.write(80);
    servo_pin_7.write(75);
    servo_pin_11.write(70);
    delay(500);
    first = false;
  }
  forward3();
}

void forward3() {
  int i;
  for (i = 0; i < 500; i++) {
         if (i > 300) servo_pin_3.write(90 + (a - 90) / (500 - i));
         servo_pin_8.write(85 + (a - 85) / (500 - i));
         servo_pin_4.write(80 + (b - 80) / (500 - i));
         servo_pin_7.write(75 + (a - 75) / (500 - i));
         servo_pin_11.write(70 + (b - 70) / (500 - i));
         delay(1);
  }
  delay(300);
  for (i = 0; i < 500; i++) {
         if (i > 300) servo_pin_3.write(90 + (10 - 90) / (500 - i));
         servo_pin_8.write(85 + (b - 85) / (500 - i));
         servo_pin_4.write(80 + (a - 80) / (500 - i));
         servo_pin_7.write(75 + (b - 75) / (500 - i));
         servo_pin_11.write(70 + (a - 70) / (500 - i));
         delay(1);
  }
  delay(300);
}

void forward1() {
  int i;
  for(i=0;i<500;i++){
         servo_pin_3.write(90+(a-90)/(500-i));
         servo_pin_8.write(85+(a-85)/(500-i));
         servo_pin_4.write(80+(b-80)/(500-i));
         servo_pin_7.write(75+(a-75)/(500-i));
         servo_pin_11.write(70+(b-70)/(500-i));
         delay(1);
  }
  delay(400);
  for(i=0;i<500;i++){
         servo_pin_3.write(90+(10-90)/(500-i));
         servo_pin_8.write(85+(b-85)/(500-i));
         servo_pin_4.write(80+(a-80)/(500-i));
         servo_pin_7.write(75+(b-75)/(500-i));
         servo_pin_11.write(70+(a-70)/(500-i));
         delay(1);
  }
  delay(400);
}

void forward2() {
    int i;
//  for (i = 0; i < 500; i++) {
//         servo_pin_3.write(90+(a-90)/(500-i));
//         servo_pin_8.write(85+(a-85)/(500-i));
//         servo_pin_4.write(80+(b-80)/(500-i));
//         servo_pin_7.write(75+(b-75)/(500-i));
//         servo_pin_11.write(70+(50-70)/(500-i));
//         delay(1);
//  }
//  delay(400);
  for (i = 0; i < 500; i++) {
         servo_pin_3.write(90+(5-90)/(500-i));
         servo_pin_8.write(85+(b-85)/(500-i));
         servo_pin_4.write(80+(a-80)/(500-i));
         servo_pin_7.write(75+(b-75)/(500-i));
         servo_pin_11.write(70+(a-70)/(500-i));
         delay(1);
  }
  delay(300);
}
