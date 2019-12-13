#ifndef WMPasBuzzer_H
#define WMPasBuzzer_H

#include "WMPort.h"

class WMPasBuzzer :
	public WMPort
{
public:

	WMPasBuzzer(uint8_t port);

	void setBuzzerTone(uint16_t frequency, uint32_t duration);
	
	uint8_t pin;
	
};
#endif