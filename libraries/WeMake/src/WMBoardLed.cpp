#include "WMBoardLed.h"

WMBoardLed::WMBoardLed(uint8_t data)
{
	pin = data;
}


void WMBoardLed::setLedStatus(uint8_t status)
{
	if(status == 1)
	{
		writeDport(pin,true);
	}
	else
	{
		writeDport(pin,false);
	}
}
