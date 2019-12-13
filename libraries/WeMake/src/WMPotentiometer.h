#ifndef WMPotentiometer_H
#define WMPotentiometer_H

#include "WMPort.h"

class WMPotentiometer :
	public WMPort
{
public:

	WMPotentiometer(uint8_t port);

	int16_t getPtm(void);
	
	uint8_t pin;
	
};
#endif