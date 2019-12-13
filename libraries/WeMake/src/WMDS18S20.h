#ifndef WMDS18S20_H
#define WMDS18S20_H

#include "OneWire\OneWire.h"

class WMDS18S20: public OneWire {
	public:
		WMDS18S20(uint8_t pin);
		float getTemp(void);
	
};
#endif
