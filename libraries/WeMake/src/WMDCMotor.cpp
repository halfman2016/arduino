  #include "WMDCMotor.h"

WMDCMotor::WMDCMotor(uint8_t port)
{
	  //The PWM frequency is 976 Hz
#if defined(__AVR_ATmega32U4__) //MeBaseBoard use ATmega32U4 as MCU
  TCCR1A =  _BV(WGM10);
  TCCR1B = _BV(CS11) | _BV(CS10) | _BV(WGM12);

  TCCR3A = _BV(WGM30);
  TCCR3B = _BV(CS31) | _BV(CS30) | _BV(WGM32);

  TCCR4B = _BV(CS42) | _BV(CS41) | _BV(CS40);
  TCCR4D = 0;

#elif defined(__AVR_ATmega328__) // else ATmega328

  TCCR1A = _BV(WGM10);
  TCCR1B = _BV(CS11) | _BV(CS10) | _BV(WGM12);

  TCCR2A = _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS22);

#elif defined(__AVR_ATmega2560__) //else ATmega2560
  TCCR1A = _BV(WGM10);
  TCCR1B = _BV(CS11) | _BV(CS10) | _BV(WGM12);

  TCCR2A = _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS22);
#endif
  	dirPin = wmPort[port].pin1;
   	pwmPin = wmPort[port].pin2;
   
}




 void WMDCMotor::run(int16_t speed)
{
  if(speed > 100)
  {
  	speed = 100;
  }
  else if(speed < -100)
  {
  	speed = -100;
  }

  int32_t value = speed  * 255/100;
 // Serial.print("value");
//  Serial.println(value);
  if(speedBck != speed)
  {
    speedBck = speed;
  }
  else
  {
    	return;
  }

  if(value >= 0)
  {
	writeDport(dirPin,1);
	writeAport(pwmPin,(int16_t)value);
  }
  else
  {
	writeDport(dirPin,0);
	writeAport(pwmPin,(int16_t)(-value));

  }
}

void WMDCMotor::reverseRun(int16_t speed)
{
		run(speed * -1);
}

 void WMDCMotor::stop(void)
{
  WMDCMotor::run(0);
}

