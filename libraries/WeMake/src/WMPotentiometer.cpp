#include "WMPotentiometer.h"

WMPotentiometer::WMPotentiometer(uint8_t port)
{
	pin = wmPort[port].pin2;	
}

int16_t WMPotentiometer::getPtm(void)
{
	int16_t adValue = WMPort::readAport(pin);
	adValue = (10*adValue)/102;
//	Serial.print("value:");
//  	Serial.println(adValue);
	return adValue;
}