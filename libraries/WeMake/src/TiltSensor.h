#ifndef TiltSensor_H
#define TiltSensor_H

#include "Adafruit_Unified_Sensor/Adafruit_Sensor.h"
#include "Adafruit_ADXL345/Adafruit_ADXL345_U.h"
#include "WMPort.h"


class TiltSensor
{
	private:
		float dx;
		float dy;
		float dz;
		
	public:
		Adafruit_ADXL345_Unified accel;
		sensors_event_t event;
		TiltSensor();
		int getAngle(uint8_t type);
		void tiltBegin();
};
#endif