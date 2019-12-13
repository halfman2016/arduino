#ifndef WMDCMotor_H
#define WMDCMotor_H

#include "WMPort.h"

class WMDCMotor:public WMPort
{
	public:
		WMDCMotor(void);
		WMDCMotor(uint8_t port);


		void run(int16_t speed);
		void reverseRun(int16_t speed);

		void stop(void);
	private:
  		volatile uint8_t dirPin;
 		volatile uint8_t pwmPin;
 		int16_t  speedBck;
};
#endif
