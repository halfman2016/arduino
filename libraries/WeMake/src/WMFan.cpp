#include "WMFan.h"

WMFan::WMFan(uint8_t port)
{
	pinClock = wmPort[port].pin1;
	pinAntiClock = wmPort[port].pin2;
}

void WMFan::setFanStatus(bool direction,int16_t speed)
{
	if(speed > 100)
		speed = 100;
	else if(speed < 0)
		speed = 0;
	speed = speed * 178/100;
	if(direction)//正转
	{
		writeAport(pinClock,speed);
		writeAport(pinAntiClock, 0);
	}
	else//反转
	{
		writeAport(pinAntiClock,speed);
		writeAport(pinClock, 0);
	}
}

void WMFan::setFanStop()
{
	writeAport(pinClock,0);
	writeAport(pinAntiClock, 0);
}