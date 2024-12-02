#include <Wire.h>
#include <AIT1001.h>

AIT1001 sensor(0x0A); // Replace 0x0A with your sensor's I2C address

void setup() {
  Serial.begin(9600);
  while (!Serial);
  if (sensor.begin()) {
    Serial.println("AIT1001 sensor initialized successfully.");
  } else {
    Serial.println("Failed to initialize AIT1001 sensor.");
  }
}

void loop() {
  float ambientTemp = sensor.readAmbientTemperature();
  float objectTemp = sensor.readObjectTemperature();

  if (!isnan(ambientTemp) && !isnan(objectTemp)) {
    Serial.print("Ambient Temperature: ");
    Serial.print(ambientTemp);
    Serial.println(" °C");

    Serial.print("Object Temperature: ");
    Serial.print(objectTemp);
    Serial.println(" °C");
  } else {
    Serial.println("Error reading temperature data.");
  }

  delay(1000); // Wait for 1 second before the next reading
}
