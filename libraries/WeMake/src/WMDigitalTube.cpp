#include "WMDigitalTube.h"


WMDigitalTube::WMDigitalTube(uint8_t port):TM1640(wmPort[port].pin2,wmPort[port].pin1)
{
	
}

WMDigitalTube::WMDigitalTube(uint8_t pinDat,uint8_t pinCLK):TM1640(pinDat,pinCLK)
{
	
}

void WMDigitalTube::setDisplay(int pos,const char* string)
{
	clearDisplay();
	setDisplayToString(string,0,pos);
}

void WMDigitalTube::setDisplay(int pos,double data)
{
	clearDisplay();
	signed char width = 0;
	unsigned char prec = 0;
	if(data < 10)
	{
		width = 1;
		prec = 3;
	}
	else if(data < 100)
	{
		width = 2;
		prec = 2;
	}
	else if(data < 1000)
	{
		width = 3;
		prec = 1;
	}
	else if(data < 10000)
	{
		width = 4;
		prec = 0;
	}

	char text[10];
	dtostrf(data,width,prec,text);
	setDisplayToStringEx(text,width,pos);
		
}
//	virtual void setDisplayToString(const char* string, const word dots = 0, const byte pos = 0,
//		const byte font[] = FONT_DEFAULT);
void WMDigitalTube::setDisplay(int pos,int data)
{
	//setDisplayDigit(data,2,true);	
	clearDisplay();
	char text[10];
	sprintf(text, "%d",data);
	setDisplayToString(text,0,pos);
}

void WMDigitalTube::setDisplay(int pos,long data)
{
	clearDisplay();
	char text[10];
	sprintf(text, "%ld",data);
	setDisplayToString(text,0,pos);
}