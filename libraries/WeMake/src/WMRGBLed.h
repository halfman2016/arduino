#ifndef WMRGBLed_H
#define WMRGBLed_H

#include "WMPort.h"


typedef struct
{
  uint8_t g;
  uint8_t r;
  uint8_t b;
}RGB;

class WMRGBLed :
	public WMPort
{
public:

	WMRGBLed(uint8_t port);
	WMRGBLed(uint8_t pin1,uint8_t led_num);
	~WMRGBLed(void);

	void reset(uint8_t port);
	void setNumber(uint8_t num_leds);
	RGB getColorAt(uint8_t index);
	uint8_t getNumber(void);
	bool setColorAt(uint8_t index, uint8_t red, uint8_t green, uint8_t blue);
	bool setColor(uint8_t index, uint8_t red, uint8_t green, uint8_t blue);
	bool setColor(uint8_t red, uint8_t green, uint8_t blue);
	bool setColor(uint8_t index, long value);
	void rgbled_sendarray_mask(uint8_t *data, uint16_t datlen, uint8_t maskhi, uint8_t *port);
	void show(void);
	void setpin(uint8_t port);
	
	
private:
	uint8_t pin;
	uint16_t count_led;
  	uint8_t *pixels;
	const volatile uint8_t *ws2812_port;
  	volatile uint8_t *ws2812_port_reg;
  	uint8_t pinMask;
};
#endif