#ifndef WMLight_H
#define WMLight_H

#include "WMPort.h"

class WMLight :
	public WMPort
{
public:

	WMLight(uint8_t port);

	WMLight(uint8_t Pin,bool flag);

	int16_t getLight(void);
	
	uint8_t pin;
	
};
#endif


