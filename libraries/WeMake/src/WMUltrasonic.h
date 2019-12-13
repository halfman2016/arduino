#ifndef WMUltrasonic_H
#define WMUltrasonic_H

#include "SR04/SR04.h"
#include "WMPort.h"

class WMUltrasonic:public SR04
{
	public:
		WMUltrasonic(uint8_t echoPin,uint8_t triggerPin);
};
#endif