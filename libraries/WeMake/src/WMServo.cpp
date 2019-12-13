#include "WMServo.h"



WMServo::WMServo(uint8_t port):SoftwareSerial(wmPort[port].pin2,wmPort[port].pin1)
{
	begin();
}

WMServo::WMServo(uint8_t rx,uint8_t tx):SoftwareSerial(rx,tx)
{
	begin();
}

void WMServo::begin(void)
{
	SoftwareSerial::begin(9600);
}

void WMServo::setPosition(int servonum,int position,int time)
{
//	uint8_t sendData[]={0x55,0x55,0x08,0x03,0x01,(uint8_t)time,(uint8_t)(time >> 8),servoNum,(uint8_t)position,(uint8_t)(position >> 8)};
//	Serial.write(sendData,10);
	if(servonum == 7)
	{
		SoftwareSerial::write(0x55);
		SoftwareSerial::write(0x55);
		SoftwareSerial::write(0x17);
		SoftwareSerial::write(0x03);
		SoftwareSerial::write(0x06);
		sendData(time);
		SoftwareSerial::write(1);
		sendData(position);
		SoftwareSerial::write(2);
		sendData(position);
		SoftwareSerial::write(3);
		sendData(position);
		SoftwareSerial::write(4);
		sendData(position);
		SoftwareSerial::write(5);
		sendData(position);
		SoftwareSerial::write(6);
		sendData(position);
	}
	else
	{
		SoftwareSerial::write(0x55);
		SoftwareSerial::write(0x55);
		SoftwareSerial::write(0x08);
		SoftwareSerial::write(0x03);
		SoftwareSerial::write(0x01);
		sendData(time);
		SoftwareSerial::write(servonum);
		sendData(position);
	}

}

void WMServo::sendData(int num)
{
	SoftwareSerial::write(uint8_t(num & 0xff));
	SoftwareSerial::write(uint8_t((num >> 8) & 0xff));
}

//int WMServo::getPosition()
//{
    //int position = 0;
	//uint8_t sendData[]={0x55,0x55,0x04,0x15,0x01,servoNum};
	//Serial.write(sendData,6);
	//delay(100);
	//uint8_t buffer[100];
	//Serial.readBytes(buffer, 100);
	//uint8_t indexFirst = 0;
	//while((buffer[indexFirst] != 0x55 || buffer[indexFirst + 1] != 0x55)&&(indexFirst < 99))
	//{
	//	indexFirst++;
	//}
	//if(indexFirst == 98)
	//{
	//	return -1;
	//}
	//else
	//{
	//	position = buffer[indexFirst + 7]*256 + buffer[indexFirst + 6];
	//}
//}

 void WMServo::motorOff()
{
//	uint8_t sendData[]={0x55,0x55,0x9,0x14,0x06,0x01,0x02,0x03,0x04,0x05,0x06};
//	Serial.write(sendData,11);
	SoftwareSerial::write(0x55);
	SoftwareSerial::write(0x55);
	SoftwareSerial::write(0x09);
	SoftwareSerial::write(0x14);
	SoftwareSerial::write(0x06);
	SoftwareSerial::write(0x01);
	SoftwareSerial::write(0x02);
	SoftwareSerial::write(0x03);	
	SoftwareSerial::write(0x04);
	SoftwareSerial::write(0x05);
	SoftwareSerial::write(0x06);
}

void WMServo::setActionSpeed(int percent)
{
	SoftwareSerial::write(0x55);
	SoftwareSerial::write(0x55);
	SoftwareSerial::write(0x05);
	SoftwareSerial::write(0x0b);
	SoftwareSerial::write(0xFF);
	sendData(percent);	
}

void WMServo::runActionGroup(uint8_t number,int times)
{
	if(times ==0)
		return;
//	uint8_t sendData[]={0x55,0x55,0x5,0x06,number,(uint8_t)times,(uint8_t)(times >> 8)};
//	Serial.write(sendData,7);
	SoftwareSerial::write(0x55);
	SoftwareSerial::write(0x55);
	SoftwareSerial::write(0x05);
	SoftwareSerial::write(0x06);
	SoftwareSerial::write(number);	
	sendData(times);
}

 void WMServo::runActionGroupRepeat(uint8_t number)
 {
// 	uint8_t sendData[]={0x55,0x55,0x5,0x06,number,0x00,0x00};
//	Serial.write(sendData,7);
	SoftwareSerial::write(0x55);
	SoftwareSerial::write(0x55);
	SoftwareSerial::write(0x05);
	SoftwareSerial::write(0x06);
	SoftwareSerial::write(number);	
	SoftwareSerial::write((uint8_t)0x0);
	SoftwareSerial::write((uint8_t)0x0);
 }