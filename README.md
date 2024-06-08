# Smart Irrigation System with ESP32 and Blynk

## Introduction
The Smart Irrigation System is designed to help optimize water usage for gardening and agriculture. By using an ESP32 microcontroller, along with soil moisture, temperature, and humidity sensors, the system can automatically control a water pump to maintain ideal soil conditions. The Blynk IoT platform enables real-time monitoring and remote control via a mobile app, providing convenience and efficiency in managing irrigation.

## Overview
This project implements a smart irrigation system using ESP32 microcontroller, Blynk IoT platform, and various sensors. The system is designed to monitor soil moisture, temperature, and humidity, and automatically control the water pump to ensure optimal conditions for plant growth.

## Features
- Real-time monitoring of soil moisture, temperature, and humidity.
- Automatic watering based on soil moisture levels.
- Remote control and monitoring via the Blynk mobile app.
- Temperature and soil moisture threshold alerts.

## Hardware Components
- ESP32 microcontroller board
- Soil moisture sensor (capacitive)
- DHT11 temperature and humidity sensor
- Water pump
- Relay module
- Jumper wires
- Power source (battery or power adapter)

## Software Requirements
- Arduino IDE
- Blynk IoT platform (mobile app)
- Libraries:
  - Blynk (BlynkSimpleEsp32.h)
  - DHT sensor library (DHT.h)
  - WiFi library (WiFi.h)

## Installation and Setup
1. Clone or download this repository to your local machine.
2. Open the Arduino IDE and navigate to `File > Open` to open the project.
3. Install the required libraries via `Sketch > Include Library > Manage Libraries...`.
4. Connect the hardware components according to the circuit diagram.
5. Configure the Blynk app with the provided authentication token.
6. Upload the sketch to the ESP32 board.
7. Power on the system and monitor the sensor readings in the Blynk app.

## Usage
- Open the Blynk app to monitor real-time sensor data and control the water pump remotely.
- Set the desired temperature and soil moisture thresholds in the app.
- Receive alerts and notifications when thresholds are exceeded.

## Circuit Diagram
[Circuit Diagram.png] (https://github.com/youscodes/Smart-Irrigation-ESP32-Blynk/blob/72fd567fa7fe5aca5c4e1d89fcb18d9eb60958f5/Circuit%20Diagram.png)

## Code
https://github.com/youscodes/Smart-Irrigation-ESP32-Blynk/blob/df79ac143d5f87bfdb94b8180cc4a3d3402e89bd/smart_irrigation.ino

## License
This project is licensed under the [MIT License](LICENSE).
