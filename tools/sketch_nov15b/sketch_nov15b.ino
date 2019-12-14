#include <SoftwareSerial.h>

// creates a "virtual" serial port/UART

// connect BT module TX to D10

// connect BT module RX to D11

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);



}

void loop() {
  // put your main code here, to run repeatedly:
sendcmd();
}
void sendcmd()
{
    Serial.println("AT");
  while(Serial.available())
  {
    char ch;
    ch = Serial.read();
    Serial.print(ch);
  } // Get response: OK
  delay(1000); // wait for printing 

}
