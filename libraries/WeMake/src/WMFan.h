#ifndef WMFan_H
#define WMFan_H

#include "WMPort.h"

class WMFan :
	public WMPort
{
public:

	WMFan(uint8_t port);

	void setFanStatus(bool direction,int16_t speed);
	void setFanStop();
	
	uint8_t pinClock;//��ת��
	uint8_t pinAntiClock;//��ת��
	
};
#endif