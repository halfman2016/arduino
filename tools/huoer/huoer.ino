#define HER A1
 int r;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:


r=analogRead(HER);
Serial.println(r);
delay(100);
}
