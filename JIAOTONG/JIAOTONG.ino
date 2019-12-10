#include <Servo.h> 
#include <MsTimer2.h>
Servo msetc;  // create servo object to control a servo 
Servo msin;
Servo msout;// twelve servo objects can be created on most boards
 
#define RED 5000
#define GREEN 5000
#define DZETC  5
#define DZIN   6
#define DZOUT  9
#define DZTIME 3000
#define FAN1 A1
#define FAN2 A2
#define FAN3 A3
#define IRETC 12
#define IRIN  10
#define IROUT 11
#define IRHLD 3 //中断 1
#define HLDRED 8
#define HLDGREEN 7


int lighgtcolor=0;
int pos=0;
void setup() {
  // put your setup code here, to run once:
pinMode(HLDRED,OUTPUT);
pinMode(HLDGREEN,OUTPUT);
pinMode(IRETC,INPUT);
pinMode(IRIN,INPUT);
pinMode(IROUT,INPUT);
pinMode(IRHLD,INPUT);

msetc.attach(DZETC); 
msin.attach(DZIN);
msout.attach(DZOUT);
Serial.begin(9600);

MsTimer2::set(5000, onTimer); //设置中断，每1000ms进入一次中断服务程序 onTimer()
MsTimer2::start(); //开始计时
attachInterrupt(digitalPinToInterrupt(3), redlight, HIGH); //注意, 0代表的是中斷編號,不是腳位哦！D3腳位的中斷編號為1, 所以此處需放1
}

void loop() {
  // put your main code here, to run repeatedly:
  
 if(digitalRead(IRETC)==HIGH){
  //etc
  up(msetc);
  delay(DZTIME);
  down(msetc);
  }

   if(digitalRead(IRIN)==HIGH){
  //IN遮挡
  up(msin);
  delay(DZTIME);
  down(msin);
  }
   if(digitalRead(IROUT)==HIGH){
  //OUT遮挡
  
  up(msout);
  delay(DZTIME);
  down(msout);
  }
   
 //风扇

 fan(FAN1,FAN2,FAN3);
 
}


void up(Servo ser){
  ser.write(0);
  }

void down(Servo ser){
   ser.write(90);
  }
  
void fan(int a,int b,int c){
   for(int i=0;i<180;i++){
   analogWrite(a,i);
   analogWrite(b,i);
   analogWrite(c,i);
   delay(40);
   }
}

void onTimer()
{
    Serial.println("on time");

  if(lighgtcolor==0)
{
   digitalWrite(HLDRED,HIGH);
  digitalWrite(HLDGREEN,LOW);

  lighgtcolor=1;
  }else{
  digitalWrite(HLDGREEN,HIGH);
  digitalWrite(HLDRED,LOW);
  lighgtcolor=0;
 }
}
void redlight(){
  //红灯
  digitalWrite(HLDRED,HIGH);
  digitalWrite(HLDGREEN,LOW);
  Serial.println("redlight");
  delay(RED);
  
  digitalWrite(HLDGREEN,HIGH);
  digitalWrite(HLDRED,LOW);
  delay(GREEN);
 }
