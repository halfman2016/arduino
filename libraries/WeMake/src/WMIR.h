#ifndef WMIR_H
#define WMIR_H

#include "SoftwareSerial/SoftwareSerial.h"
#include "WMPort.h"

typedef enum
{
	IR_NO_MATCH,//IR值不匹配
	IR_MATCH,//IR值匹配
	IR_PING,//IR红外ping码0xFFFFFFFF
	IR_PING_NOT_MATCH//IR红外ping码不能匹配当前查询值
}IR_Match_State;

class WMIR:public SoftwareSerial
{
	public:
		WMIR(void);

		WMIR(uint8_t port);
		void begin(void);
		bool keyPressed(int value);

		bool keyPressedLong(int value);
		void startDecode(void);

		int currentValue;
		int currentlongValue;
		int currentlongValueBcp;
		bool headStart;
};

#endif

