#include "WMPasBuzzer.h"

WMPasBuzzer::WMPasBuzzer(uint8_t port)
{
	pin = port;
}

void WMPasBuzzer::setBuzzerTone(uint16_t frequency, uint32_t duration)
{
	int period = 1000000L / frequency;
  	int pulse = period / 2;
	setOutput(pin);
  	for (long i = 0; i < duration * 1000L; i += period) 
  	{
    	writeDport(pin, 1);
    	delayMicroseconds(pulse);
    	writeDport(pin, 0);
    	delayMicroseconds(pulse);
  	}
	delay(20);
}
