#include "WMButton.h"

WMButton::WMButton()
{
}

WMButton::~WMButton()
{
}

WMButton::WMButton(uint8_t port)
{
	pin = wmPort[port].pin1;
}

WMButton::WMButton(uint8_t Pin,bool flag)
{
	pin = Pin;
}

bool WMButton::pressed(void)
{
	return !WMPort::readDPuPort(pin);
}