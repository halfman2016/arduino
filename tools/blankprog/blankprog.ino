#include <SoftwareSerial.h>
int txPin = 9;//接蓝牙TX口
int rxPin = 10;//接蓝牙RX口
//XIAOCHE 
//SoftwareSerial BTSerial(9,10); 

// BAN 
SoftwareSerial BTSerial(4,2); 

void setup() 
{  
  Serial.begin(9600);//  
  BTSerial.begin(9600);  // 这里设置蓝牙通信波特率，刚买来的一般是38400
}

void loop()
{
  if (BTSerial.available())//从蓝牙那里读取数据
    Serial.write(BTSerial.read());//打印在串口中


  if (Serial.available())//从串口读取数据，传给蓝牙
    BTSerial.write(Serial.read());
}
