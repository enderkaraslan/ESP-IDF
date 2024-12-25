# First Project with ESP32

Welcome to your first project with the ESP32! This README will guide you through the setup and basic usage of your ESP32 development board.

## Table of Contents
- [Introduction](#introduction)
- [Requirements](#requirements)
- [Setup](#setup)
- [Usage](#usage)
- [Troubleshooting](#troubleshooting)
- [Contributing](#contributing)
- [License](#license)

## Introduction
The ESP32 is a powerful, low-cost microcontroller with integrated Wi-Fi and Bluetooth capabilities. This project will help you get started with the basics of using the ESP32.

## Requirements
- ESP32 development board
- USB cable
- Computer with Arduino IDE installed
- Internet connection

## Setup
1. **Install Arduino IDE**: Download and install the Arduino IDE from the [official website](https://www.arduino.cc/en/software).
2. **Install ESP32 Board in Arduino IDE**:
    - Open Arduino IDE.
    - Go to `File` > `Preferences`.
    - In the "Additional Board Manager URLs" field, add the following URL: `https://dl.espressif.com/dl/package_esp32_index.json`.
    - Go to `Tools` > `Board` > `Boards Manager`.
    - Search for "ESP32" and click "Install".
3. **Connect ESP32 to Computer**: Use the USB cable to connect your ESP32 board to your computer.
4. **Select ESP32 Board**: In Arduino IDE, go to `Tools` > `Board` and select your ESP32 board model.
5. **Select Port**: Go to `Tools` > `Port` and select the port to which your ESP32 is connected.

## Usage
1. **Open Example Sketch**: Go to `File` > `Examples` > `WiFi` and select `WiFiScan`.
2. **Upload Sketch**: Click the upload button to compile and upload the sketch to your ESP32.
3. **Open Serial Monitor**: Go to `Tools` > `Serial Monitor` to view the output from your ESP32.

## Troubleshooting
- **Board Not Detected**: Ensure the USB cable is properly connected and try a different USB port.
- **Compilation Errors**: Verify that you have selected the correct board and port in the Arduino IDE.

## Contributing
Contributions are welcome! Please fork this repository and submit a pull request with your improvements.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.