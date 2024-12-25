<<<<<<< HEAD
#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#define pdSECOND pdMS_TO_TICKS(1000)

//#include "Gpio.h"
#include "Wifi.h"
#include "nvs_flash.h"
//#include "Potentiometer.h"
//#include "Uart.h"

#include "EspErrorHandler.h"

class Main final
{
public:
    esp_err_t setup(void);
    void run(void);

    EspErrorHandler handler;


    //Gpio::GpioOutput led{GPIO_NUM_32};
    //Gpio::GpioInput button{GPIO_NUM_33};
    WIFI::Wifi my_wifi;
    //Sensor::Potentiometer my_potentiometer{};
    //Serial_comms::Uart my_uart{};

=======
#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#define pdSECOND pdMS_TO_TICKS(1000)

#include "Gpio.h"
#include "Wifi.h"

class Main final
{
public:
    esp_err_t setup(void);
    void run(void);

    Gpio::GpioOutput led{GPIO_NUM_32};
    Gpio::GpioInput button{GPIO_NUM_33};
    WIFI::Wifi my_wifi;
>>>>>>> 8bdcc15964fc771d3f9424f95387928eb9075170
};