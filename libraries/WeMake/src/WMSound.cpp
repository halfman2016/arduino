#include "WMSound.h"

WMSound::WMSound(uint8_t port)
{
	pin = wmPort[port].pin2;
}

WMSound::WMSound(uint8_t Pin,bool flag)
{
	pin = Pin;
}

int16_t WMSound::getSound(void)
{
	int16_t adValue = WMPort::readAport(pin);
	
//	Serial.print("ad:");
//	Serial.println(adValue);

	if(adValue < 18)
	{
		adValue = 0;
	}
	else
	{
		adValue = adValue - 18;
	}

	if(adValue < 50)
	{
		adValue = adValue / 2;
	}
	else
	{
		int16_t temp = (adValue - 50) * 7 / 54;
		if(temp < 75)
		{
			adValue = temp;
		}
		else
		{
			adValue = 75;
		}
		adValue= adValue+25;
	}
	Serial.print("convert:");
	Serial.println(adValue);
	return(adValue);
}