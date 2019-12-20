//right board

//串口屏
//1602
//光照
//土壤湿度
//温度湿度
//485串口 读取风向2 ph1 风速3 4800

#include <SoftwareSerial.h>
#include <OS_SerialTFT.h>  
#include <LiquidCrystal_I2C.h>
#include <BH1750.h>
#include <dht.h>

#define MOI A1
#define D A0
#define TX 7
#define RX 8

LiquidCrystal_I2C lcd(0x27,16,2);
SerialTFT myTFT(RX, TX);
dht DHT;
BH1750 lightMeter;  //I2C 接口
int m=0,l=0;
int t,h;

SoftwareSerial port485(4, 2); // RX, TX
unsigned char cmdph[]={0x01,0x03,0x00,0x08,0x00,0x01,0x05,0xc8};
int i=0;

unsigned char data[8];


void setup(){
  Serial.begin(9600);
  myTFT.begin(9600);
  myTFT.reset();
  
  myTFT.fillScreen(BLACK);
  myTFT.setBacklight(100);//0~255
  myTFT.setTextSize(5);
  myTFT.setRotation(3);
  myTFT.setCursor(110,80);
   myTFT.fillScreen(BLACK);
  myTFT.print("GXEX");
 
  lcd.begin(); // for 16 x 2 LCD module 
  lcd.backlight(); 
  lcd.home (); // set cursor to 0,0 
  lcd.setCursor (0,1); // go to start of 2nd line 
  lcd.print("ok");
  lightMeter.begin();

}

void loop(){
 
displaythlm1602();

delay(500);

}

void displaythlm1602(){
DHT.read11(D);
t=DHT.temperature;
h=DHT.humidity;
m=analogRead(MOI);
l=lightMeter.readLightLevel();

lcd.setCursor(0,0);
lcd.print("T :");
lcd.print(t);
lcd.print(" C");


lcd.setCursor(8,0);
lcd.print("H :");
lcd.print(h);
lcd.print("%");

lcd.setCursor(0,1);
lcd.print("L :");
lcd.print(l);
lcd.print(" l");

lcd.setCursor(8,1);

lcd.print("M :");
lcd.print(m);
lcd.print("");

  }
