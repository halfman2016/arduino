

void setup() {
  // put your setup code here, to run once:
pinMode(12,INPUT);
Serial.begin(9600);
Serial.println(LED_BUILTIN);
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

if(digitalRead(12)==HIGH){
  Serial.println("have");
  for(int i =0 ;i<1;i++){
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  
  }
  }
}
