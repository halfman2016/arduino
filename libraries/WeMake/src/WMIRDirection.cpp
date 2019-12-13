#include "WMIRDirection.h"

WMIRDirection::WMIRDirection(uint8_t ir1,uint8_t ir2,uint8_t ir3,uint8_t ir4)
{
	IR1 = ir1;
	IR2 = ir2;
	IR3 = ir3;
	IR4 = ir4;

	pinMode(IR1, INPUT);
  	pinMode(IR2, INPUT);
  	pinMode(IR3, INPUT);
  	pinMode(IR4, INPUT);
}

bool WMIRDirection:: getDirection(uint8_t oriention)
{
	int count;
  	bool l, r, u, d;
  	count = 10000;

   l = digitalRead(IR1);
   r = digitalRead(IR2);
   u = digitalRead(IR3);
   d = digitalRead(IR4);
   if (l == LOW && r == HIGH)
   {
     
     while (count > 0)
     {
       l = digitalRead(IR1);
       r = digitalRead(IR2);
       if (r == LOW && l == HIGH)
       {
         direction = RIGHT;
         //Serial.println("RIGHT");
         break;
       } else {
         count--;
         delayMicroseconds(50);
       }
     }
   }
   else if (r == LOW && l == HIGH)
   {
     while (count > 0)
     {
       l = digitalRead(IR1);
       r = digitalRead(IR2);
       if (l == LOW && r == HIGH)
       {
         direction = LEFT;
         //Serial.println("LEFT");
         break;
       } else {
         count--;
         delayMicroseconds(50);
       }
     }
   }
   else if ( u == LOW && d == HIGH)
   {
     while (count > 0)
     {
       u = digitalRead(IR3);
       d = digitalRead(IR4);
       if (d == LOW && u == HIGH)
       {
         direction = DOWN;
         //Serial.println("DOWN");
         break;
       } else {
         count--;
         delayMicroseconds(50);
       }
     }
   }
   else if ( d == LOW && u == HIGH)
   {
     while (count > 0)
     {
       u = digitalRead(IR3);
       d = digitalRead(IR4);
       if (u == LOW && d == HIGH)
       {
         direction = UP;
         //Serial.println("UP");
         break;
       } else {
         count--;
         delayMicroseconds(50);
       }
     }
   }
   else
   {
   }
   return (direction == oriention);
}
