
int ii=0;
void setup() {
  // put your setup code here, to run once:
pinMode(12,INPUT);
Serial.begin(9600);
Serial.println(LED_BUILTIN);
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

if(digitalRead(12)!=LOW){
  
  
  }
  else
  {
      Serial.println(ii);
  ii++;

    }
  
  delay(100);
}
