int i ;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(4,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(4)==HIGH){
  Serial.println(i++);
  }
}
