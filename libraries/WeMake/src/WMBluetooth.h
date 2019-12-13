#ifndef WMBluetooth_H
#define WMBluetooth_H

#include "SoftwareSerial/SoftwareSerial.h"
#include "WMPort.h"



class WMBluetooth:public SoftwareSerial
{
	public:
		WMBluetooth(void);

		WMBluetooth(uint8_t port);
		WMBluetooth(uint8_t pin1,uint8_t pin2);
		void begin(void);
		void startDecode(void);
		int currentValue;
		void sendData(const char* string);
		void sendData(int num);
		void sendData(double num);
		int16_t getConstant(int16_t value);
		void sendDistanceData(int16_t value);
		void sendVersion();
		void sendRebackCmd(int16_t value);
};

#endif

