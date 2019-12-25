#include <Wire.h> 
//#include <LCD.h> 
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,16,2); // 0x27 is the I2C bus address for an unmodified backpack 
void setup() { // activate LCD module 
  lcd.begin (); // for 16 x 2 LCD module 

  lcd.setBacklight(HIGH); 
} 
void loop() { 
  lcd.home (); // set cursor to 0,0 
  lcd.print(" test.com"); 
  lcd.setCursor (10,1); // go to start of 2nd line 
  lcd.print(millis()); 
  delay(1000); 
  //lcd.setBacklight(LOW); // Backlight off delay(250);        
 // lcd.setBacklight(HIGH); // Backlight on delay(1000); 
}
