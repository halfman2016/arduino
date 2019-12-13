#include "WMLight.h"

WMLight::WMLight(uint8_t port)
{
	pin = wmPort[port].pin2;
}

WMLight::WMLight(uint8_t Pin,bool flag)
{
	pin = Pin;
}

int16_t WMLight::getLight(void)
{
	int16_t adValue = WMPort::readAport(pin);
//	Serial.print("ad:");
//	Serial.println(adValue);
	if(adValue < 25)
	{
		adValue = 100 - adValue;
	}
	else
	{
		adValue = (1023 - adValue)*7/93;
	}
//	Serial.print("convert:");
//	Serial.println(adValue);
	return(adValue);
}