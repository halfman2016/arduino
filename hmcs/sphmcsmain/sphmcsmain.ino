//海绵城市，2块主控
//一、红绿灯交通灯控制和小车协同
//二、路灯、土壤温湿度、以及显示


//主控
//土壤湿度信号线A1插口
//气温，空气湿度A2接口

#include <BH1750.h> //光强
#include <LiquidCrystal_I2C.h> //1602屏幕

//#include <dht.h>  //温度
//#include <OS_SerialTFT.h>


#define MOS A1 //土壤湿度信号线A1插口
//#define TH  A2 //气温，空气湿度A2接口
#define LUDENG 13 //路灯继电器控制口
int LON=50 ;  //开灯临界值，低于定义自动开灯


//屏幕


//dht DHT;
BH1750 lightMeter;  //I2C 接口
//SerialTFT myTFT(TFT_RX, TFT_TX);  //屏幕

int t,m,h,l;  //温度，土壤湿度，空气湿度，光强度
uint16_t curlight=0;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  lcd.begin (16,2); // for 16 x 2 LCD module 
  lcd.setBacklightPin(3,POSITIVE); 
  lcd.setBacklight(HIGH); 
  lcd.home (); // set cursor to 0,0 
  lcd.print(" test.com"); 
  lcd.setCursor (10,1); // go to start of 2nd line 
  lcd.print(millis()); 

 lightMeter.begin(); //光强初始化
 pinMode(LUDENG,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
l=lightMeter.readLightLevel();
Serial.print("light:");
Serial.print(l);

if(curlight == l)
    {
      
    }
    else
    {
    curlight = l;
    Serial.print("NEW L");
    Serial.print(curlight);
    if (curlight < LON)
  {
     digitalWrite(LUDENG,HIGH);
    delay(10);
  }
  else
  {
     digitalWrite(LUDENG,LOW);
     delay(10);

    }
    }

        
   m=analogRead(A1);
  //DHT.read11(A2);
 //t=DHT.temperature;
  //h=DHT.humidity;


      Serial.print("M:");
      Serial.println(m);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Light   :"); lcd.print(l);lcd.print(" lux");  
lcd.setCursor (0,1); // go to start of 2nd line 
lcd.print("Moisture:");  lcd.print(m); 

   delay(1000);
}
