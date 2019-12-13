#include "WMBoardIR.h"

WMBoardIR::WMBoardIR(uint8_t port):IRrecv(port)
{
	currentValue = 0;
	currentlongValue = 0;
	readValidValue = 0;
	headStart = false;
}
void WMBoardIR::begin(void)
{
	enableIRIn(); 
}


void WMBoardIR::startDecode(void)//¿ªÊ¼½âÎö
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
		
		if(currentValue != 0xff)//pingÂë
		{
			currentlongValue = currentValue;
			readValidValue = currentValue;
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

bool WMBoardIR::keyPressed(int value)
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
  currentValue = 0;
  if(readValidValue == value)
	{
		readValidValue = 0;
		return true;
	}
	return false;
 	
//	if(return_flag)
//		Serial.println("press");
//	return return_flag;
}


bool WMBoardIR::keyPressedLong(int value)
{
	//if(headStart && currentlongValue == value)
	//	Serial.println("press");
	return (headStart && currentlongValue == value);
}
