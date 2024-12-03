AIT1001 Arduino Library

## Table of Contents
- [Introduction](#introduction)
- [Features](#Features)
- [Installation](#installation)
    - [Arduino IDE Library Manager](#arduino-ide-library-manager)
    - [Installing Manually from GitHub](#installing-manually-from-github)
- [Usage](#usage)
  - [Basic Usage](#basic-usage)
  - [Wiring Details](#wiring-details)
- [Examples](#examples)
- [Error Handling](#error-handling)
- [Troubleshooting](#troubleshooting)
- [FAQ](#faq)
- [Compatibility](#compatibility)
- [Contributing](#contributing)
- [License](#license)
- [External References](#external-references)


## Introduction
This Arduino library is designed for the AIT1001 non-contact infrared temperature sensor. It simplifies the process of reading both ambient and object temperature, allowing for seamless integration into your Arduino projects.

Manufacturer: Aosong Electronics
Author: Mayank Sunhare
Version: 1.0.0
License: MIT

## Features
I2C Communication: Simplifies integration via the I2C protocol.
Object and Ambient Temperature Readings: Provides precise measurements of both temperatures.
Configurable I2C Address: Allows customization of the sensor's address for multi-device setups.
Error Handling: Built-in mechanisms for handling communication errors.

## Installation

### Arduino IDE Library Manager
Open the Arduino IDE.
Navigate to Sketch > Include Library > Manage Libraries....
Search for "AIT1001" in the Library Manager.
Install the AIT1001 library.

### Installing Manually from GitHub
Download the latest release of the library as a ZIP file.
Open the Arduino IDE.
Navigate to Sketch > Include Library > Add .ZIP Library....
Select the downloaded ZIP file to install.

## Usage

### Basic Usage
Include the AIT1001.h header in your sketch.
Initialize the sensor object with its I2C address.
Use readAmbientTemperature() and readObjectTemperature() methods to retrieve temperature readings.


#include <Wire.h>
#include <AIT1001.h>

AIT1001 sensor(0x0A); // Replace 0x0A with the sensor's I2C address

void setup() {
  Serial.begin(9600);
  if (sensor.begin()) {
    Serial.println("AIT1001 Initialized Successfully");
  } else {
    Serial.println("Initialization Failed");
  }
}

void loop() {
  float ambient = sensor.readAmbientTemperature();
  float object = sensor.readObjectTemperature();
  Serial.print("Ambient Temp: ");
  Serial.print(ambient);
  Serial.print(" °C, Object Temp: ");
  Serial.print(object);
  Serial.println(" °C");
  delay(1000);
}

### Wiring Details
SDA (Data line): Connect to Arduino A4.
SCL (Clock line): Connect to Arduino A5.
GND: Ground connection.
VCC: Power supply (3.3V or 5V).

## Examples
Basic Example: Demonstrates how to read temperatures using the sensor.
Custom Address: Shows how to initialize the sensor with a custom I2C address.

## Error Handling
If communication with the sensor fails:

readAmbientTemperature() and readObjectTemperature() return NAN.

## Troubleshooting
Ensure correct wiring and power supply.
Verify the I2C address using an I2C scanner sketch.

## FAQ
Can I connect multiple AIT1001 sensors to one Arduino?
Yes, by assigning unique I2C addresses to each sensor.

What is the measurement range of the sensor?

Ambient Temperature: -25°C to 100°C
Object Temperature: -25°C to 100°C
What is the default I2C address?
The default address is 0x0A.

## Compatibility
This library has been tested with:

Arduino Uno
Arduino Mega
ESP32

## Contributing
Contributions are welcome! Submit your pull requests or report issues via the GitHub repository.

## License
This library is licensed under the MIT License. See the LICENSE file for details.

## External References

- [`Sensor manufacturer`](http://www.aosong.com/m/en/products-116.html)
