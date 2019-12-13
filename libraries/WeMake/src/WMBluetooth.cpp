#include "WMBluetooth.h"

WMBluetooth::WMBluetooth(uint8_t port):SoftwareSerial(wmPort[port].pin2,wmPort[port].pin1)
{

}

WMBluetooth::WMBluetooth(uint8_t pin1,uint8_t pin2):SoftwareSerial(pin1,pin2)
{
}

void WMBluetooth::begin(void)
{
	SoftwareSerial::begin(9600);
}


void WMBluetooth::startDecode(void)//开始解析
{

	delay(10);
	
	if(SoftwareSerial::available())//判断串口有数据
	{
		int value = SoftwareSerial::read();
		if(value != -1)//获取到串口数据
		{
			currentValue = value;
		}
	}
	else
	{
	}
}

void WMBluetooth::sendData(const char* string)
{
	int i = 0;
	while(string[i] != '\0')
	{
		SoftwareSerial::write(uint8_t(string[i]));
		i++;
	}
	
}

void WMBluetooth::sendData(int num)
{
	SoftwareSerial::write(uint8_t(num & 0xff));
	SoftwareSerial::write(uint8_t((num >> 8) & 0xff));
}

void WMBluetooth::sendData(double num)
{
    
	SoftwareSerial::write(uint8_t((int)num & 0xff));
	SoftwareSerial::write(uint8_t(((int)num >> 8) & 0xff));
}

int16_t WMBluetooth::getConstant(int16_t value)
{
	return value;
}

void WMBluetooth::sendDistanceData(int16_t value)
{
	SoftwareSerial::write(0x55);
	SoftwareSerial::write(0x55);
	SoftwareSerial::write(0x04);
	SoftwareSerial::write(0x03);
	sendData(value);
}

void WMBluetooth::sendVersion()
{
	SoftwareSerial::write(0x55);
	SoftwareSerial::write(0x55);
	SoftwareSerial::write(0x04);
	SoftwareSerial::write(0x05);
	SoftwareSerial::write(0x71);
	SoftwareSerial::write(0x01);
}

void WMBluetooth::sendRebackCmd(int16_t value)
{
	SoftwareSerial::write(0x55);
	SoftwareSerial::write(0x55);
	SoftwareSerial::write(0x04);
	SoftwareSerial::write(0x01);
	SoftwareSerial::write(uint8_t(value & 0xff));
	SoftwareSerial::write(0xff);
}