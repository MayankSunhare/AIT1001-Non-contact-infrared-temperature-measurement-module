#ifndef AIT1001_H
#define AIT1001_H

#include <Wire.h>

class AIT1001 {
  public:
    AIT1001(uint8_t address = 0x0A); // Constructor with default I2C address
    bool begin();
    float readAmbientTemperature();
    float readObjectTemperature();
  private:
    uint8_t _address;
    bool readTemperatureData(uint16_t &ambient, uint16_t &object);
};

#endif
