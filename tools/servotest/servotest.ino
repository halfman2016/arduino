#include <Servo.h> 
#include <LiquidCrystal_I2C.h>
//pwm都可以用 a0~5 d3 5 6 9 10 11 均可，自行修改pin
Servo sa0;
Servo sa1;
Servo sa2;
Servo sa3;
Servo sa4;
Servo sa5;

#define ETC A0

#define DZTIME 3000
LiquidCrystal_I2C lcd(0x27,16,2);


void up(Servo ser){
 // lcd.print(" Up..Wait..Down.. ");
  ser.write(90);
  
  }

void down(Servo ser){
   
   ser.write(0);

  }
 void doall(int a,Servo ser){
  lcd.clear();
  lcd.print(a);
  lcd.print(" Do");
  up(ser);
  delay(DZTIME);
  down(ser);
  }

int who=0;

void setup() {
  // put your setup code here, to run once:

  //pwm都可以用 a0~5 d3 5 6 9 10 11 均可，自行修改pin
  
sa0.attach(ETC);
sa1.attach(A1);
sa2.attach(A2);

//sa3.attach(A3);
//sa4.attach(A4);
//sa5.atta)ch(A5);
  // put your main code here, to run repeatedly:

lcd.begin();

}



void loop() {

up(sa0);
up(sa1);
up(sa2);
lcd.clear();
lcd.print("UP");
delay(2000);

lcd.clear();
lcd.print("DOWN");
down(sa0);
down(sa1);
down(sa2);
delay(2000);

    

}
