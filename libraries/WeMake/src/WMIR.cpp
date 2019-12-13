#include "WMIR.h"

WMIR::WMIR(uint8_t port):SoftwareSerial(wmPort[port].pin2,wmPort[port].pin1)
{
	currentValue = 0;
	currentlongValue = 0;
	currentlongValueBcp = 0;
	headStart = false;
}
void WMIR::begin(void)
{
	SoftwareSerial::begin(9600);
}

/*
void WMIR::startDecode(void)//开始解析
{
	decode_results results;
	static int decode_count = 0;
	delay(10);
	if(decode(&results))
	{
		decode_count = 0;
		currentValue = (results.value >> 8)&0xff;
//		Serial.print("currentValue:");
//		Serial.println(currentValue);
//		Serial.print("currentlongValue:");
//		Serial.println(currentlongValue);
		if(currentValue != 0xff)//ping码
		{
			currentlongValue = currentValue;
			headStart = true;
//			Serial.println("get head");
		}
		resume();
				
	}
	else
	{
		//Serial.println("no code");
		if(headStart)
		{
			decode_count++;
			if(decode_count > 10)
			{
				decode_count = 0;
				headStart = false;
				currentlongValue = 0;
	//			Serial.println("cancel");
			}
		}
		else
		{
			decode_count = 0;
			currentlongValue = 0;
			currentValue = 0;
		}
	}
}
*/

void WMIR::startDecode(void)//开始解析
{

	static int decode_count = 0;
	delay(10);
	
	if(SoftwareSerial::available())//判断串口有数据
	{
		int value = SoftwareSerial::read();
		if(value != -1)//获取到串口数据
		{
			decode_count = 0;
			//Serial.print("get value:");
			//Serial.println(value);
			currentValue = value;
			if(currentValue != 0xff)//ping码
			{
				currentlongValueBcp = currentValue;
			}
			else
			{
				currentlongValue = currentlongValueBcp;
				headStart = true;
				//Serial.println("get head");
			}
		}
	}
	else
	{
			//Serial.println("no code");
			if(headStart)
			{
				decode_count++;
				if(decode_count > 2)
				{
					decode_count = 0;
					headStart = false;
					currentlongValue = 0;
					//Serial.println("cancel");
				}
			}
			else
			{
				decode_count = 0;
				currentlongValue = 0;
				currentValue = 0;
			}
	}
}

bool WMIR::keyPressed(int value)
{
//	bool return_flag = 0;
//	decode_results results;
	 
//	if(decode(&results)) 
//	{
//		if(IR_MATCH == findIR(&results,value))
//		{
//			return_flag = 1;
//		}
 //   	resume(); // Receive the next value
 //    }
 	 if(currentValue == value)
	{
			//Serial.println("press");
		currentValue = 0;
		return true;
	}
	return false;
 	
//	if(return_flag)
//		Serial.println("press");
//	return return_flag;
}


bool WMIR::keyPressedLong(int value)
{
	//if(headStart && currentlongValue == value)
	//	Serial.println("press");
	return (headStart && currentlongValue == value);
}
