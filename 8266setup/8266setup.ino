#include <SoftwareSerial.h>
boolean firstTime = true;
String returnStr = "";
SoftwareSerial mySerial(13, 12); // RX, TX
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Goodnight moon!");
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);//set esp8266 boud 9600
}
 
void loop() { // run over and over
    while(firstTime){
        mySerial.println("test");
        delay(800);
        while(mySerial.available() > 0){
                returnStr += char(mySerial.read());
                delay(2);
        }
        if(returnStr.length() < 1){
            firstTime = false;
            break;
        }
        
        returnStr = "";
        mySerial.println("AT+RST");
        while(true){//wait for ok
            while(mySerial.available() > 0){
                returnStr += char(mySerial.read());
                delay(2);
            }
            if(returnStr.lastIndexOf("invalid") != -1){
                Serial.println(returnStr);
                break;
            }
        }
        
        returnStr = "";
        mySerial.println("AT+CIPMODE=1");
        while(true){//wait for ok
            while(mySerial.available() > 0){
                returnStr += char(mySerial.read());
                delay(2);
            }
            if(returnStr.lastIndexOf("OK") != -1){
                Serial.println(returnStr);
                break;
            }
        }
        
        returnStr = "";
        mySerial.println("AT+CWJAP=\"Chen302lab\",\"au302lab\"");
        while(true){//wait for ok
            while(mySerial.available() > 0){
                returnStr += char(mySerial.read());
                delay(2);
            }
            if(returnStr.lastIndexOf("OK") != -1){
                Serial.println(returnStr);
                break;
            }
        }
        
        returnStr = "";
        mySerial.println("AT+CIPMUX=0");
        while(true){//wait for ok
            while(mySerial.available() > 0){
                returnStr += char(mySerial.read());
                delay(2);
            }
            if(returnStr.lastIndexOf("OK") != -1){
                Serial.println(returnStr);
                break;
            }
        }
        
        
        returnStr = "";
        mySerial.println("AT+CIPSTART=\"TCP\",\"192.168.1.114\",8080");
        while(true){//wait for ok
                while(mySerial.available() > 0){
                    returnStr += char(mySerial.read());
                    delay(2);
                }
                if(returnStr.lastIndexOf("OK") != -1){
                    Serial.println(returnStr);
                    break;
                }
        }
        
        returnStr = "";
        mySerial.println("AT+CIPSEND");
        while(true){//wait for ok
                while(mySerial.available() > 0){
                    returnStr += char(mySerial.read());
                    delay(2);
                }
                if(returnStr.lastIndexOf("OK") != -1){
                    Serial.println(returnStr);
                    break;
                }
        }
        firstTime = false;
    }//
    
    if (mySerial.available()) 
        Serial.write(mySerial.read());
    if (Serial.available()) {
        mySerial.write(Serial.read());
        
    }
        
  
}
