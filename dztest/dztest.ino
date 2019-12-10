#include <Servo.h> 
#include <MsTimer2.h>
Servo msetc;

void setup() {
  // put your setup code here, to run once:
msetc.attach(6); 
up(msetc);
delay(3000);
down(msetc);
delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void up(Servo ser){
  ser.write(0);
  }

void down(Servo ser){
   ser.write(90);
  }
  
