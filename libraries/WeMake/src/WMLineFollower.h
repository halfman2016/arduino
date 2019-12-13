#ifndef WMLineFollower_H
#define WMLineFollower_H

#include "WMPort.h"




#define 	S1_OUT_S2_OUT 0x00//传感器1和传感器2都在黑线外
#define 	S1_OUT_S2_IN 0x01//传感器1在黑线外，传感器2在黑线内
#define 	S1_IN_S2_OUT 0x02//传感器1在黑线内传感器2在黑线外	
#define 	S1_IN_S2_IN  0x03//传感器1和传感器2都在黑线内

class WMLineFollower:public WMPort
{
	public:
		WMLineFollower(void);
		WMLineFollower(uint8_t port);
		WMLineFollower(uint8_t pin1,uint8_t pin2);
		bool readSensor1Status();
		bool readSensor2Status();
		bool readEdgeSensor1Status();
		bool readEdgeSensor2Status();

		/*
		*函数描述:返回传感器状态
		*返回值:传感器状态
		*参数:空
		*/

		int readSensors(void);

		
		/*
		*函数描述:返回传感器状态
		*返回值:传感器状态
		*参数:传感器对比状态
		*/
		bool readSensorStatus(uint8_t sensorStatus);

	private:
		volatile uint8_t sensor1Pin;
		volatile uint8_t sensor2Pin;
		
};

#endif
