#include <Arduino.h>
#include "Wire.h"
#include <WMHead.h>
#include <WMBoard.h>
#include <Adafruit_TCS34725.h>

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
int bt,remote;
int red,green,blue,clear,sum;
int fspeed,bspeed,stop;
int c1min,c1max,c2min,c2max,c3min,c3max,c4min,c4max,c5min,c5max;
int lag1,lag2,lag3;
int c1r,c1g,c1b,c2r,c2g,c2b,c3r,c3g,c3b,c4r,c4g,c4b,c5r,c5g,c5b,xx;

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
WMRGBLed rgbLED(0,4);
SR04 sr04 = SR04(4,3);
WMBoardIR boardIr(13);
WMDCMotor motor1(8);
WMDCMotor motor2(7);
WMLineFollower lineFollower1(11,12);


void setup() 
{
boardIr.begin();
rgbLED.setColor(0,255,255,0);
rgbLED.show();
bt=remote=0;
red=green=blue=clear=sum=0;
c1min=c1max=c2min=c2max=c3min=c3max=c4min=c4max=c5min=c5max=0;
lag1=100;
lag2=600;
lag3=30000;
stop=0;
fspeed=30;
bspeed=-30;
c1r=15000;    //红色
c1g=0;
c1b=0;
//c2r=;
//c2g=;
//c2b=;
c3r=10200;    //蓝色
c3g=0;
c3b=0;
c4r=4800;    //黄色
c4g=0;
c4b=0;
c5r=2500;    //浅蓝色
c5g=0;
c5b=0;
xx=1000;
c1min=c1r+c1g+c1b-xx;
c1max=c1r+c1g+c1b+xx;
//c2min=c2r+100*c2g+10000*c2b-10101*xx;
//c2max=c2r+100*c2g+10000*c2b+10101*xx;
c3min=c3r+c3g+c3b-xx;
c3max=c3r+c3g+c3b+xx;
c4min=c4r+c4g+c4b-xx;
c4max=c4r+c4g+c4b+xx;
c5min=c5r+c5g+c5b-xx;
c5max=c5r+c5g+c5b+xx;
motor1.reverseRun(fspeed);
motor2.reverseRun(fspeed);
}

void loop() 
{
	boardIr.startDecode();
	tcs.getRawData(&red, &green, &blue, &clear);
	sum=green;
	//sum=red+green+blue;	//有待优化
	if(boardIr.keyPressed(48))//数字1按键
	{
		remote=1;
	}
	else
	{
		if(boardIr.keyPressed(24))//数字2按键
		{
			remote=2;
		}
		else
		{
			if(boardIr.keyPressed(122))//数字3按键
			{
				remote=3;
			}
		}
	}
	switch(remote)
	{
		case 1:
		rgbLED.setColor(0,255,0,0);
		rgbLED.show();
		if((sr04.Distance()<10))
		{
			motor1.reverseRun(stop);
			motor2.reverseRun(stop);
		}
		else
		{
			if(lineFollower1.readSensorStatus(0))
			{
				motor1.reverseRun(fspeed);
				motor2.reverseRun(fspeed);
			}
			else
			{
				if(lineFollower1.readSensorStatus(1))
				{
					motor1.reverseRun(50);
					motor2.reverseRun(10);
				}
				else
				{
					if(lineFollower1.readSensorStatus(2))
					{
						motor1.reverseRun(10);
						motor2.reverseRun(50);
					}
					else
					{
						if(sum>c1min&&sum<c1max)
						{	
							delay(6000);
						}
						else
						{
							if(sum>c2min&&sum<c2max)
							{	
								delay(6000);
							}
						}
					}
				}
			}
		}
		break;
		
		case 2:
		rgbLED.setColor(0,0,255,0);
		rgbLED.show();
		if((sr04.Distance()<10))
		{
			motor1.reverseRun(stop);
			motor2.reverseRun(stop);
		}
		else
		{
			if(lineFollower1.readSensorStatus(0))
			{
				motor1.reverseRun(fspeed);
				motor2.reverseRun(fspeed);
			}
			else
			{
				if(lineFollower1.readSensorStatus(1))
				{
					motor1.reverseRun(50);
					motor2.reverseRun(10);
				}
				else
				{
					if(lineFollower1.readSensorStatus(2))
					{
						motor1.reverseRun(10);
						motor2.reverseRun(50);
					}
					else
					{
						if(sum>c1min&&sum<c1max)
						{	
							delay(6000);
						}
						else
						{
							if(sum>c2min&&sum<c2max)
							{	
								delay(6000);
							}
							else
							{
								if(sum>c3min&&sum<c3max)
								{
									motor1.reverseRun(fspeed);
									motor2.reverseRun(fspeed);
									delay(lag1);
									motor1.reverseRun(bspeed);
									motor2.reverseRun(fspeed);
									delay(lag2);
									motor1.reverseRun(fspeed);
									motor2.reverseRun(fspeed);
								}
								else
								{
									if(sum>c4min&&sum<c4max)
									{
										motor1.reverseRun(fspeed);
										motor2.reverseRun(fspeed);
										delay(lag1);
										motor1.reverseRun(fspeed);
										motor2.reverseRun(bspeed);
										delay(lag2);
										motor1.reverseRun(fspeed);
										motor2.reverseRun(fspeed);
									}
								}
							}
						}
					}
				}
			}
		}
		break;
		
		case 3:
		tcs.getRawData(&red, &green, &blue, &clear);
		sum=red+green+blue;
		rgbLED.setColor(0,0,0,255);
		rgbLED.show();
		if((sr04.Distance()<10))
		{
			motor1.reverseRun(stop);
			motor2.reverseRun(stop);
		}
		else
		{
			if(lineFollower1.readSensorStatus(0))
			{
				motor1.reverseRun(fspeed);
				motor2.reverseRun(fspeed);
			}
			else
			{
				if(lineFollower1.readSensorStatus(1))
				{
					motor1.reverseRun(50);
					motor2.reverseRun(10);
				}
				else
				{
					if(lineFollower1.readSensorStatus(2))
					{
						motor1.reverseRun(10);
						motor2.reverseRun(50);
					}
					else
					{
						if(sum>c1min&&sum<c1max)
						{	
							delay(6000);
						}
						else
						{
							if(sum>c2min&&sum<c2max)
							{	
								delay(6000);
							}
							else
							{
								if(sum>c3min&&sum<c3max)
								{
									motor1.reverseRun(fspeed);
									motor2.reverseRun(fspeed);
									delay(lag1);
									motor1.reverseRun(bspeed);
									motor2.reverseRun(fspeed);
									delay(lag2);
									motor1.reverseRun(fspeed);
									motor2.reverseRun(fspeed);
								}
								else
								{
									if(sum>c4min&&sum<c4max)
									{
										motor1.reverseRun(fspeed);
										motor2.reverseRun(fspeed);
										delay(lag1);
										motor1.reverseRun(fspeed);
										motor2.reverseRun(bspeed);
										delay(lag2);
										motor1.reverseRun(fspeed);
										motor2.reverseRun(fspeed);
									}
									else
									{
										if(sum>c5min&&sum<c5max)
										{
											motor1.reverseRun(stop);
											motor2.reverseRun(stop);
											delay(lag3);
											motor1.reverseRun(fspeed);
											motor2.reverseRun(fspeed);
										}
									}
								}
							}
						}
					}
				}
			}
		}
		break;
	}
}
