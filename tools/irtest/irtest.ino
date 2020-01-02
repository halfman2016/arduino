#include <LiquidCrystal_I2C.h>

int ii=0;
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
pinMode(3,INPUT_PULLUP);
pinMode(5,INPUT_PULLUP);
pinMode(6,INPUT_PULLUP);
//pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(7,OUTPUT);
lcd.begin();

Serial.begin(9600);
pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

if(digitalRead(3)==LOW){

ii++;
 lcd.print("3:");
 lcd.println(ii);
  }
  
if(digitalRead(5)==LOW){

ii++;
 lcd.print("5:");
 lcd.println(ii);
  }
  if(digitalRead(6)==LOW){

ii++;
 lcd.print("6:");
 lcd.println(ii);
  }
  if(digitalRead(13)==LOW){

ii++;
 lcd.print("13:");
 lcd.println(ii);
  }
//  if(digitalRead(12)==LOW){
//
//ii++;
// lcd.print("12:");
// lcd.println(ii);
//  }
//  if(digitalRead(7)==LOW){
//
//ii++;
// lcd.print("7:");
// lcd.println(ii);
//  }
delay(3000);
digitalWrite(7,HIGH); //green
//digitalWrite(13,HIGH);
//digitalWrite(12,LOW);

lcd.println("green");

//delay(3000);
//digitalWrite(7,LOW);
//digitalWrite(12,HIGH);
//
//lcd.println("RED");
//  

  
}
