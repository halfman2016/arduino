#ifndef WM_SERVO_H
#define WM_SERVO_H

#include "SoftwareSerial/SoftwareSerial.h"
#include "WMPort.h"

class WMServo:public SoftwareSerial
{
	private:
		uint8_t port;
	public:
		WMServo(void);
		WMServo(uint8_t port);
		WMServo(uint8_t rx,uint8_t tx);

		void begin(void);
		void sendData(int num);

		void setPosition(int servonum,int position,int time);

		void setActionSpeed(int percent);
		
	    void motorOff();
		void runActionGroup(uint8_t number,int time);
		void runActionGroupRepeat(uint8_t number);
};
#endif
