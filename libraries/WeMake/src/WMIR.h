#ifndef WMIR_H
#define WMIR_H

#include "SoftwareSerial/SoftwareSerial.h"
#include "WMPort.h"

typedef enum
{
	IR_NO_MATCH,//IRֵ��ƥ��
	IR_MATCH,//IRֵƥ��
	IR_PING,//IR����ping��0xFFFFFFFF
	IR_PING_NOT_MATCH//IR����ping�벻��ƥ�䵱ǰ��ѯֵ
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

