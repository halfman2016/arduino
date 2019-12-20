#include <SoftwareSerial.h>

SoftwareSerial BT(8,7);  //rx 8 tx 07
char val;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
BT.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

if(BT.available())
{
  val=BT.read();
  Serial.print(val);
  }
}
