void setup() {
  // put your setup code here, to run once:
pinMode(8,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(8,HIGH);//输出HIGH电平，继电器模块闭合
delay(2000); //等待5000毫秒
digitalWrite(8,LOW);//输出LOW电平，继电器模块断开
delay(100);
}
