#pragma once

#include "driver/gpio.h"


namespace Gpio
{
class GpioBase
{
protected:
    const gpio_num_t _pin;
    const bool _inverted_logic = false;
    const gpio_config_t _cfg;

public:
    constexpr GpioBase(const gpio_num_t pin, 
                const gpio_config_t& config, 
                const bool inverted_logic = false) :
        _pin{pin},
        _inverted_logic{inverted_logic},
        _cfg{config}
        
    {

    }

    virtual bool state(void) =0;
    

    [[nodiscard]] esp_err_t init(void);

}; // GpioBase

class GpioOutput : public GpioBase
{
    bool _state = false;

public:
    constexpr GpioOutput(const gpio_num_t pin, const bool invert = false) :
        GpioBase{pin, 
                    gpio_config_t
                    {
                        .pin_bit_mask = static_cast<uint64_t>(1) << pin,
                        .mode         = GPIO_MODE_OUTPUT,
                        .pull_up_en   = GPIO_PULLUP_DISABLE,
                        .pull_down_en = GPIO_PULLDOWN_ENABLE,
                        .intr_type    = GPIO_INTR_DISABLE,
                    }, 
                    invert}
    {

    }

    [[nodiscard]] esp_err_t init(void); 

    esp_err_t set(const bool state); // Pinin durumunu ayarlar (HIGH veya LOW)
    esp_err_t toggle(void); // Pinin mevcut durumunu tersine çevirir
    bool state(void) { return _state; } // LED'in şu anki durumunu döner (true veya false)

}; // GpioOutput


class GpioInput : public GpioBase
{
    bool _state = false;
public:
    constexpr GpioInput(const gpio_num_t pin, const bool invert = false) :
        GpioBase{pin,
                gpio_config_t
                {
                    .pin_bit_mask = static_cast<uint64_t>(1) << pin,
                    .mode         = GPIO_MODE_INPUT,
                    .pull_up_en   = GPIO_PULLUP_DISABLE,
                    .pull_down_en = GPIO_PULLDOWN_ENABLE,
                    .intr_type    = GPIO_INTR_DISABLE,
                },
                invert}
    {

    }

    [[nodiscard]] esp_err_t init(void);

    bool state(void);

}; // GpioInput



} // namespace Gpio