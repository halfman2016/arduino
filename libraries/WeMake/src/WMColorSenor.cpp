#include "WMColorSenor.h"

WMColorSenor::WMColorSenor(uint8_t s0,uint8_t s1,uint8_t s2,uint8_t s3,uint8_t out)
{
	S0 = s0;
	S1 = s1;
	S2 = s2;
	S3 = s3;
	OUT = out;
	
	pinMode(S0, OUTPUT);   //Configure the S0 pin as an output
  	pinMode(S1, OUTPUT);   //Configure the S1 pin as an output
  	pinMode(S2, OUTPUT);   //Configure the S2 pin as an output
 	pinMode(S3, OUTPUT);   //Configure the S3 pin as an output
  	pinMode(OUT, INPUT);   //Configure the S4 pin as an output

  	digitalWrite(S0, HIGH); //S0 set low, S1 set high, the color sensor internal frequency is 20%
  	digitalWrite(S1, HIGH);

/*
	delay(1500);
//Detect white
    R_F =  readFreq(RED);
    G_F =  readFreq(GREEN);
    B_F =  readFreq(BLUE);
    //Measure twice, and then calculate their average.
    R_F =  (readFreq(RED) + R_F) / 2;
    G_F = (readFreq(GREEN) + G_F) / 2;
    B_F = (readFreq(BLUE) + B_F) / 2 ;

	delay(3000);
//Detect black
   r_f = readFreq(RED);
   g_f = readFreq(GREEN);
   b_f = readFreq(BLUE);
 
   //Measure twice, and then calculate their average.
   r_f = (readFreq(RED) + r_f) / 2;
   g_f = (readFreq(GREEN) + g_f) / 2;
   b_f = (readFreq(BLUE) + b_f) / 2;
   */
}

void WMColorSenor::checkWhite()
{
    R_F =  readFreq(RED);
    G_F =  readFreq(GREEN);
    B_F =  readFreq(BLUE);
    //Measure twice, and then calculate their average.
    R_F =  (readFreq(RED) + R_F) / 2;
    G_F = (readFreq(GREEN) + G_F) / 2;
    B_F = (readFreq(BLUE) + B_F) / 2 ;
}

void WMColorSenor::checkBlack()
{
   r_f = readFreq(RED);
   g_f = readFreq(GREEN);
   b_f = readFreq(BLUE);
 
   //Measure twice, and then calculate their average.
   r_f = (readFreq(RED) + r_f) / 2;
   g_f = (readFreq(GREEN) + g_f) / 2;
   b_f = (readFreq(BLUE) + b_f) / 2;
}

int WMColorSenor::readFreq(uint8_t CC) {
  switch (CC) {
    case RED: 
      digitalWrite(S2, LOW);
      digitalWrite(S3, LOW);
      break;
    case GREEN:  
      digitalWrite(S2, HIGH);
      digitalWrite(S3, HIGH);
      break;
    case BLUE:    
      digitalWrite(S2, LOW);
      digitalWrite(S3, HIGH);
      break;
    case WHITE:  
      digitalWrite(S2, HIGH);
      digitalWrite(S3, LOW);
      break;
  }
  int freq = pulseIn(OUT, LOW);  //About pulseIn https://www.arduino.cc/en/Reference/PulseIn
  return  1000 * 1000 / (freq * 2);  //Convert the pulse width to frequency
}

bool WMColorSenor::colorDetect(uint8_t color)
{
  int r, g, b, t = 0;
  r = readFreq(RED);
  g = readFreq(GREEN);
  b = readFreq(BLUE);

  //Convert the measured frequency to the corresponding value in the 0-255. About map https://www.arduino.cc/en/Reference/Map
  
  r = map(r, r_f, R_F, 0, 255);  
  g = map(g, g_f, G_F, 0, 255);
  b = map(b, b_f, B_F, 0, 255);

  
  if (r > g)
    t = RED;
  else
    t = GREEN;
  if (t == GREEN && g < b)
    t = BLUE;
  if (t == RED && r < b)
    t = BLUE;
  //Serial.print("R:"); Serial.print(r);
 // Serial.print("  G:"); Serial.print(g);
  //Serial.print("  B:"); Serial.println(b);

  //Returns the color only if the RGB value is greater than 30, otherwise returns 0
  if(t == BLUE && b > 50)
  {
  }
  else if(t == GREEN && g > 50)
  {
  }
  else if(t == RED && r > 50)
  {
  }
  else 
    return false;
  return (t == color);
}
