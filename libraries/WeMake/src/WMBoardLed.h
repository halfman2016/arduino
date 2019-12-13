#ifndef WMBoardLed_H
#define WMBoardLed_H

#include "WMPort.h"

class WMBoardLed :
	public WMPort
{
public:
	WMBoardLed(uint8_t data);
	void setLedStatus(uint8_t status);

	uint8_t pin;
};

#endif
