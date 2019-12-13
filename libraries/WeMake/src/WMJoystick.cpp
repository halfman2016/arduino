#include "WMJoystick.h"

WMJoystick::WMJoystick(uint8_t port)
{
	xPort = wmPort[port].pin1;
	yPort = wmPort[port].pin2;
	xAdValue = 0;
	yAdValue = 0;
}

int16_t WMJoystick::getXYPos(bool axis)
{
	int16_t adXValue = 0;
	int16_t adYValue = 0;
	adXValue = WMPort::readAport(xPort);
	adYValue = WMPort::readAport(yPort);
//	Serial.print("xPos:");
//	Serial.println(adXValue);
//	Serial.print("yPos:");
//	Serial.println(adYValue);
	if(axis)
	{
		if(adXValue == 0 && adYValue == 0)
		{
			return xAdValue;
		}
		else
		{
			xAdValue = adXValue;
			return (xAdValue * 10 /103);
		}
	}
	else
	{
		if(adXValue == 0 && adYValue == 0)
		{
			return yAdValue;
		}
		else
		{
			yAdValue = adYValue;
			return yAdValue * 10 /103;
		}
	}
}

//bool WMJoystick::getJoystickBtnPress(void)
//{
//	int16_t adXValue = 0;
//	int16_t adYValue = 0;
//	adXValue = WMPort::readAport(xPort);
//	adYValue = WMPort::readAport(yPort);
//	Serial.print("xPos:");
//	Serial.println(adXValue);
//	Serial.print("yPos:");
//	Serial.println(adYValue);
//	if(adXValue == 0 && adYValue == 0)
//	{
//		return true;
//	}
//	return false;
//}

