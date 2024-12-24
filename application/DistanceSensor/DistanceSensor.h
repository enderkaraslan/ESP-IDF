#pragma once 

#include "Gpio.h"
#include "EspErrorHandler.h"
#include "esp_rom_sys.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


#define pd50MS pdMS_TO_TICKS(50)

constexpr float sound_speed = 343.0f;

namespace Sensor
{
class DistanceSensor
{
private:
    Gpio::GpioOutput _trig_pin; 
    Gpio::GpioInput _echo_pin; 


public:
    
    DistanceSensor(const gpio_num_t trig_pin, const gpio_num_t echo_pin) 
        : _trig_pin(trig_pin), _echo_pin(echo_pin)
    {
        
    }

    [[nodiscard]] esp_err_t init(void);

    float get_distance(void);



}; // class DistanceSensor

}; // namespace Sensor
