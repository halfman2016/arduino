#include "WMDS18S20.h"

WMDS18S20::WMDS18S20(uint8_t pin):OneWire(pin)
{
	
}



float WMDS18S20::getTemp(void)
{
	 //returns the temperature from one DS18S20 in DEG Celsius

  byte data[12];
  byte addr[8];

  if ( !this->search(addr)) {
      //no more sensors on chain, reset search
      Serial.println("search fail");
      this->reset_search();
      return -1000;
  }

  if ( OneWire::crc8( addr, 7) != addr[7]) {
      Serial.println("CRC is not valid!");
      return -1000;
  }

  if ( addr[0] != 0x10 && addr[0] != 0x28) {
      Serial.print("Device is not recognized");
      return -1000;
  }

  this->reset();
  this->select(addr);
  this->write(0x44,1); // start conversion, with parasite power on at the end

  byte present = this->reset();
  this->select(addr);    
  this->write(0xBE); // Read Scratchpad

  
  for (int i = 0; i < 9; i++) { // we need 9 bytes
    data[i] = this->read();
  }
  
  this->reset_search();
  
  byte MSB = data[1];
  byte LSB = data[0];

  float tempRead = ((MSB << 8) | LSB); //using two's compliment
  float TemperatureSum = tempRead / 16;
  
  return TemperatureSum;
}

