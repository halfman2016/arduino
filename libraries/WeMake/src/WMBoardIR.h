#ifndef WMBOARDIR_H
#define WMBOARDIR_H

#include "IRremote\IRremote.h"
#include "WMPort.h"

class WMBoardIR:public IRrecv
{
	public:
		WMBoardIR(void);
		WMBoardIR(uint8_t port);
		void begin(void);
		bool keyPressed(int value);
		bool keyPressedLong(int value);
		void startDecode(void);

		int currentValue;
		int readValidValue;
		int currentlongValue;
		bool headStart;
};

#endif

