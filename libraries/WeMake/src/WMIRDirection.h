#ifndef WMIRDirection_H
#define WMIRDirection_H

#define LEFT   1
#define RIGHT  2
#define UP     3
#define DOWN   4

#include "WMPort.h"

class WMIRDirection
{
	private:
		uint8_t IR1;
		uint8_t IR2;
		uint8_t IR3;
		uint8_t IR4;
		int direction;
	public:
		WMIRDirection(uint8_t ir1,uint8_t ir2,uint8_t ir3,uint8_t ir4);

		bool getDirection(uint8_t oriention);
};
#endif