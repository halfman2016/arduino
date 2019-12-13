#include "WMLineFollower.h"

WMLineFollower::WMLineFollower(uint8_t port)
{
	sensor1Pin = wmPort[port].pin1;
	sensor2Pin = wmPort[port].pin2;
	setInput(sensor1Pin);
	setInput(sensor2Pin);
}

WMLineFollower::WMLineFollower(uint8_t pin1,uint8_t pin2)
{
	sensor1Pin = pin1;
	sensor2Pin = pin2;
	setInput(sensor1Pin);
	setInput(sensor2Pin);
}

int WMLineFollower::readSensors(void)
{
	int state = S1_OUT_S2_OUT;
	bool stateS1 = readDPort(sensor1Pin);
	bool stateS2 = readDPort(sensor2Pin);
	state =  ( (1 & stateS1) << 1) | stateS2;
	return state;
}

bool WMLineFollower::readSensorStatus(uint8_t sensorStatus)
{
	return (readSensors() == sensorStatus);
}

bool WMLineFollower::readSensor1Status()
{
	bool stateS1 = readDPort(sensor1Pin);
	return !stateS1;
}

bool WMLineFollower::readSensor2Status()
{
	bool stateS2 = readDPort(sensor2Pin);
	return !stateS2;
}

bool WMLineFollower::readEdgeSensor1Status()
{
	bool stateS1 = readDPort(sensor1Pin);
	return stateS1;
}

bool WMLineFollower::readEdgeSensor2Status()
{
	bool stateS2 = readDPort(sensor2Pin);
	return stateS2;
}