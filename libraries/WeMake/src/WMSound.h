#ifndef WMSound_H
#define WMSound_H

#include "WMPort.h"

class WMSound :
	public WMPort
{
public:

	WMSound(uint8_t port);
	WMSound(uint8_t Pin,bool flag);
	int16_t getSound(void);
	
	uint8_t pin;
	
};
#endif

