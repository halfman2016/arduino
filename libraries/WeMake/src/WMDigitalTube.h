#ifndef WMDigitalTube_H
#define WMDigitalTube_H

#include "TM1640/TM1640.h"
#include "WMPort.h"

class WMDigitalTube:public TM1640
{
	public:
		WMDigitalTube(void);
		WMDigitalTube(uint8_t port);
		WMDigitalTube(uint8_t pinDat,uint8_t pinCLK);
		void setDisplay(int pos,const char* string);
		void setDisplay(int pos,double data);
		void setDisplay(int pos,int data);
		void setDisplay(int pos,long data);
};

#endif
