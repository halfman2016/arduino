
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  for(int i=0;i<180;i++){
   analogWrite(A2, i);
   delay(40);
   }

}
