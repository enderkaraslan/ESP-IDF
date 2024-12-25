<<<<<<< HEAD
| Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-C5 | ESP32-C6 | ESP32-H2 | ESP32-P4 | ESP32-S2 | ESP32-S3 |
| ----------------- | ----- | -------- | -------- | -------- | -------- | -------- | -------- | -------- | -------- |

# _Sample project_

(See the README.md file in the upper level 'examples' directory for more information about examples.)

This is the simplest buildable example. The example is used by command `idf.py create-project`
that copies the project to user specified path and set it's name. For more information follow the [docs page](https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html#start-a-new-project)



## How to use example
We encourage the users to use the example as a template for the new projects.
A recommended way is to follow the instructions on a [docs page](https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html#start-a-new-project).

## Example folder contents

The project **sample_project** contains one source file in C language [main.c](main/main.c). The file is located in folder [main](main).

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt`
files that provide set of directives and instructions describing the project's source files and targets
(executable, library, or both). 

Below is short explanation of remaining files in the project folder.

```
├── CMakeLists.txt
├── main
│   ├── CMakeLists.txt
│   └── main.c
└── README.md                  This is the file you are currently reading
```
Additionally, the sample project contains Makefile and component.mk files, used for the legacy Make based build system. 
They are not used or needed when building with CMake and idf.py.
=======
# Gpio Library

This repository contains a simple C++ library for handling GPIO operations on embedded systems. The library provides an object-oriented approach for controlling GPIO pins as inputs and outputs using the ESP32 platform.

## Features

- **GPIO Output Control**: Allows setting the state (HIGH/LOW) of GPIO pins and toggling their state.
- **GPIO Input Handling**: Reads the state of GPIO pins (HIGH/LOW) and allows for basic input operations.
- **Inverted Logic**: Supports inverted logic for GPIO operations, making it flexible for various hardware configurations.

## Requirements

- ESP32 or compatible microcontroller
- ESP-IDF (Espressif IoT Development Framework)
- C++11 or later

## Installation

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/your-username/gpio-library.git
>>>>>>> 8bdcc15964fc771d3f9424f95387928eb9075170
