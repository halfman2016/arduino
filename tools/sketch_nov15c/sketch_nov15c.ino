#include <SoftwareSerial.h>
SoftwareSerial BTSerial(7,8);
char val;
void setup() {
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(38400);
}
void loop() {
  if(BTSerial.available())
    Serial.write(BTSerial.read());
  if(Serial.available())
    {
      val = Serial.read();
      Serial.println(val);
      BTSerial.write(val);
    }

}
