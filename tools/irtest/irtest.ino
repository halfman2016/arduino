#define IR 3
int ii=0;
void setup() {
  // put your setup code here, to run once:
pinMode(IR,INPUT);
Serial.begin(9600);
pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

if(digitalRead(IR)==LOW){
  
  Serial.println(ii);
  ii++;
  }
  else
  {
      

    }


  
}
