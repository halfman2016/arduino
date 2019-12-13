#ifndef WMButton_H
#define WMButton_H

#include "WMPort.h"

class WMButton :
	public WMPort
{
public:
	WMButton();
	~WMButton();

	WMButton(uint8_t port);

	WMButton(uint8_t Pin,bool flag);

	bool pressed(void);

	uint8_t pin;
};
#endif

