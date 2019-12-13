#ifndef WMJoystick_H
#define WMJoystick_H

#include "WMPort.h"

class WMJoystick :
	public WMPort
{
public:

	WMJoystick(uint8_t port);
	int16_t getXYPos(bool axis);
//	bool getJoystickBtnPress(void);

	uint8_t xPort,yPort;
	int16_t xAdValue;
	int16_t yAdValue;
};
#endif