/*

  Basic.pde - example using ModbusMaster library

  Library:: ModbusMaster
  Author:: Doc Walker <4-20ma@wvfans.net>

  Copyright:: 2009-2016 Doc Walker

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

*/

#include <SoftwareSerial.h>

SoftwareSerial mySerial(13, 12); // RX, TX
uint16_t m_startAddress = 0;
uint8_t m_length = 1;//从从站起始地址开始你需要读取的数据的长度
uint8_t result;//串口通信结果，不用明白是什么，只要知道这不是你最终需要的数据就行
unsigned char uart_Send_Buff1[8]  = {0x01,0x03,0x00,0x08,0x00,0x01,0x05,0xC8};
unsigned char uart_Send_Buff2[8]  = {0x02,0x03,0x00,0x00,0x00,0x02,0xC4,0x38};
unsigned char uart_Send_Buff3[8] ={0x03,0x03,0x00,0x00,0x00,0x01,0x85,0xE8};
unsigned char uart_Receive_Buff[9];
void setup()
{
  // use Serial (port 0); initialize Modbus communication baud rate
  Serial.begin(9600);
  mySerial.begin(4800);
}


void loop()
{int i=0;
   mySerial.write(uart_Send_Buff1, 8);
  delay(100);
while(mySerial.available()>0){
    mySerial.readBytes(uart_Receive_Buff,9);
    mySerial.flush();
  }
  delay(10);

  for(i=0;i<9;i++){
    Serial.print(uart_Receive_Buff[i],HEX);
    Serial.print(":");
    }
    Serial.println();


    
 mySerial.write(uart_Send_Buff2, 8);
  delay(100);
while(mySerial.available()>0){
    mySerial.readBytes(uart_Receive_Buff,9);
    mySerial.flush();
  }
  delay(10);

  
  for(i=0;i<9;i++){
    Serial.print(uart_Receive_Buff[i],HEX);
    Serial.print(":");
    }
    Serial.println();

    

 mySerial.write(uart_Send_Buff3, 8);
  delay(100);
   while(mySerial.available()>0){
    mySerial.readBytes(uart_Receive_Buff,9);
    mySerial.flush();
  }

  delay(10);

  
  for(i=0;i<9;i++){
    Serial.print(uart_Receive_Buff[i],HEX);
    Serial.print(":");
    }
    Serial.println();
  
}
