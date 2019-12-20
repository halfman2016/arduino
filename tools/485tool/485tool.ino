#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <ArduinoModbus.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);



void setup() {
  // put your setup code here, to run once:
  lcd.begin();
 Serial.begin(9600);
  // Turn on the blacklight and print a message.
  ModbusRTUClient.begin(4800);
  lcd.backlight();
  lcd.print("Hello, world!");
}

void loop() {
  // put your main code here, to run repeatedly:
 if (!ModbusRTUClient.requestFrom(2, HOLDING_REGISTERS, 0x00, 2)) {
    Serial.print("failed to read registers! ");
    Serial.println(ModbusRTUClient.lastError());
  } else {
    // If the request succeeds, the sensor sends the readings, that are
    // stored in the holding registers. The read() method can be used to
    // get the raw temperature and the humidity values.
    short rawtemperature = ModbusRTUClient.read();
    short rawhumidity = ModbusRTUClient.read();

    // To get the temperature in Celsius and the humidity reading as
    // a percentage, divide the raw value by 10.0.
    temperature = rawtemperature / 10.0;
    humidity = rawhumidity / 10.0;
    Serial.println(temperature);
    Serial.println(humidity);
  }

  delay(5000);
}
