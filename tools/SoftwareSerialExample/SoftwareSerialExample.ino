/*
  Software serial multple serial test

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.

 The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)

 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 Not all pins on the Leonardo and Micro support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example

 This example code is in the public domain.

 */
#include <SoftwareSerial.h>

SoftwareSerial mySerial(13, 12); // RX, TX
unsigned char Re_buf[9],counter=0;
int sign=0;
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.println("Goodnight moon!");
//01030008000105C8
  // set the data rate for the SoftwareSerial port





//  mySerial.print("01030008000105C8");
}

void loop() { // run over and over

//02 03 00 00 00 02 C4 38
 mySerial.begin(4800);
 mySerial.write(0X02);
 mySerial.write(0X03);
mySerial.write(byte(0X00));
mySerial.write(byte(0X00));
mySerial.write(byte(0X00));
 mySerial.write(0X02);
      mySerial.write(0XC4);
        mySerial.write(0X38);
   delay(5000);
  if (mySerial.available()) {
      myserialEvent();
  }
  
  if(sign){
    int i;
   for(i=0;i<9;i++){
    Serial.print(Re_buf[i],HEX);
   }
   Serial.println();
    sign=0;
    
  }

  delay(5000);

}
void myserialEvent(){
   while (mySerial.available()) {   
      Re_buf[counter]=(unsigned char)mySerial.read();
     // if(counter==0&&Re_buf[0]!=0x5A) return;      // 检查帧头         
      counter++;       
      if(counter==9)                //接收到数据
      {    
         counter=0;                 //重新赋值，准备下一帧数据的接收 
         sign=1;
      }      
      }

}
