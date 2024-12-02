#include "AIT1001.h"
#include <math.h> // Include math.h for NAN

AIT1001::AIT1001(uint8_t address) : _address(address) {}

bool AIT1001::begin() {
  Wire.begin();
  return true;
}

float AIT1001::readAmbientTemperature() {
  uint16_t ambient, object;
  if (readTemperatureData(ambient, object)) {
    return ambient * 0.1; // Convert to Celsius
  }
  return NAN; // Return Not-A-Number if read fails
}

float AIT1001::readObjectTemperature() {
  uint16_t ambient, object;
  if (readTemperatureData(ambient, object)) {
    return object * 0.1; // Convert to Celsius
  }
  return NAN; // Return Not-A-Number if read fails
}

bool AIT1001::readTemperatureData(uint16_t &ambient, uint16_t &object) {
  Wire.beginTransmission(_address);
  Wire.write(0x00); // Register to read temperature
  if (Wire.endTransmission(false) != 0) {
    return false; // Transmission failed
  }

  Wire.requestFrom(_address, (uint8_t)6);
  if (Wire.available() == 6) {
    uint8_t rawData[6];
    for (int i = 0; i < 6; i++) {
      rawData[i] = Wire.read();
    }
    ambient = (rawData[0] << 8) | rawData[1];
    object = (rawData[3] << 8) | rawData[4];
    return true;
  }
  return false; // Data not available
}
