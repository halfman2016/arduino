#include "TiltSensor.h"

TiltSensor::TiltSensor()
{

}

void TiltSensor::tiltBegin()
{
	accel = Adafruit_ADXL345_Unified(12345);
	delay(100);
	if(!accel.begin()) 
	{
    	//Serial.println("Can not detected ADXL345");
    	//digitalWrite(13, HIGH);
    	delay(100);
		if(!accel.begin()) 
		{
		}
    
	}
  accel.setRange(ADXL345_RANGE_2_G);    //Set the measured range for ADXL345
  accel.setDataRate(ADXL345_DATARATE_400_HZ); //Set the data conversion cycle for ADXL345;
}

int TiltSensor::getAngle(uint8_t type)
{
	//Serial.println("ppp");
	static uint32_t timer;         //Define the static variable Timer for timing
  	static uint32_t stepx = 0;

  	if (timer > millis())
  	{
  		return 0;
  	}
    
  	timer = millis() + 5;
  	accel.getEvent(&event);

	float ax;  //Save the acceleration of the X axis
	float ay;  //Save the acceleration of the Y axis
	float az;  //Save the acceleration of the Z axis
	
	//Wave filtering
  	ax = ax * 0.8 + event.acceleration.x * 0.2;
  	ay = ay * 0.8 + event.acceleration.y * 0.2;
  	az = az * 0.8 + event.acceleration.z * 0.2;
	if(type == 0)
	{
		dx = atan2(ax , (sqrt(ay * ay + az * az))) * 180 / PI;  //Calculate the X-axis angle
		return (int)dx;
	}
	else if(type == 1)
	{
		dy = atan2(ay , (sqrt(ax * ax + az * az))) * 180 / PI;  //Calculate the Y-axis angle
		return (int)dy;
	}
	else if(type == 2)
	{
		dz = atan2(az , (sqrt(ax * ax + ay * ay))) * 180 / PI; //Calculate the Z-axis angle
		return (int)dz;
	}

	dx = atan2(ax , (sqrt(ay * ay + az * az))) * 180 / PI;  //Calculate the X-axis angle
	
	return (int)dx;
}