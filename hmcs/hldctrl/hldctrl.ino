#include <MsTimer2.h>


#define IRHLD 3 //中断 1
#define HLDRED 12
#define HLDGREEN 13

void setup(){
  pinMode(HLDRED,OUTPUT);
  pinMode(HLDGREEN,OUTPUT);
  pinMode(IRHLD,INPUT);

  MsTimer2::set(5000, onTimer); //设置中断，每1000ms进入一次中断服务程序 onTimer()
  MsTimer2::start(); //开始计时
  attachInterrupt(digitalPinToInterrupt(3), redlight, HIGH); //注意, 0代表的是中斷編號,不是腳位哦！D3腳位的中斷編號為1, 所以此處需放1

  }

void loop(){
  
  
  }
