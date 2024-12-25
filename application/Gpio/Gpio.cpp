#include "Gpio.h"

namespace Gpio 
{

//----------------------------GpioBase----------------------------//

[[nodiscard]] esp_err_t GpioBase::init(void)
{
    EspErrorHandler handler;

    handler |= gpio_config(&_cfg);
    
    return handler.status();
}

//----------------------------GpioOutput----------------------------//

[[nodiscard]] esp_err_t GpioOutput::init(void) 
{
    EspErrorHandler handler{GpioBase::init()};

    if (ESP_OK == handler.status())
    {
        handler |= set(_inverted_logic);
    }
    return handler.status();
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
    EspErrorHandler handler{GpioBase::init()};

    if (ESP_OK == handler.status())
    {
        _state = gpio_get_level(_pin) ^ _inverted_logic; 
    }
    return handler.status();
}

bool GpioInput::state(void)
{
    _state = gpio_get_level(_pin) ^ _inverted_logic;
    return _state;
}

} // namespace Gpio