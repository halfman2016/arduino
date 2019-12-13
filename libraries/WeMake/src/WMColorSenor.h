#ifndef WM_ColorSenor_H
#define WM_ColorSenor_H

#include "WMPort.h"

#define RED   1
#define GREEN 2
#define BLUE  3
#define WHITE 4
//#define BLACK 5
//#define YELLOW 6
class WMColorSenor
{
	private:
		int R_F;
		int G_F;
		int B_F;
		int r_f;
		int b_f;
		int g_f;

		uint8_t S0;
		uint8_t S1;
		uint8_t S2;
		uint8_t S3;
		uint8_t OUT;
		
	public:
		WMColorSenor();
		WMColorSenor(uint8_t s0,uint8_t s1,uint8_t s2,uint8_t s3,uint8_t out);

		int readFreq(uint8_t CC);
		bool colorDetect(uint8_t color);
		void checkWhite();
		void checkBlack();
};

#endif
