#include "Gpio.h"

namespace Gpio 
{

//----------------------------GpioBase----------------------------//

[[nodiscard]] esp_err_t GpioBase::init(void)
{
    esp_err_t status{ESP_OK};

    status |= gpio_config(&_cfg);
    
    return status;
}

//----------------------------GpioOutput----------------------------//

[[nodiscard]] esp_err_t GpioOutput::init(void) 
{
    esp_err_t status{GpioBase::init()};

    if (ESP_OK == status)
    {
        status |= set(_inverted_logic);
    }
    return status;
}

esp_err_t GpioOutput::set(const bool state)
{
    _state = state;
    
    return gpio_set_level(_pin, 
                            _inverted_logic ? 
                                !state : 
                                state);
}

esp_err_t GpioOutput::toggle(void)
{
    _state = !_state;
    return gpio_set_level(_pin, 
                            _inverted_logic ? 
                                !_state : 
                                _state);
}

//----------------------------GpioInput----------------------------//

[[nodiscard]] esp_err_t GpioInput::init(void) 
{
    esp_err_t status{GpioBase::init()};

    if (ESP_OK == status)
    {
        _state = gpio_get_level(_pin) ^ _inverted_logic; 
    }
    return status;
}

bool GpioInput::state(void)
{
    _state = gpio_get_level(_pin) ^ _inverted_logic;
    return _state;
}

} // namespace Gpio