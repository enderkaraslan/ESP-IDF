#include "Potentiometer.h"

namespace Sensor
{
    esp_err_t Potentiometer::init() {
        // Initialize ESP-IDF error handling
        EspErrorHandler error_handler;
        
        // Configure ADC resolution
        error_handler |= adc1_config_width(_width);

        // Configure channel attenuation
        error_handler |= adc1_config_channel_atten(_channel, _attenuation);

        return error_handler.status();
    }

    int Potentiometer::read_raw() const {

        return adc1_get_raw(_channel);
    }

    int Potentiometer::read_scaled_value() const {
        int raw = read_raw();

        return static_cast<int>((static_cast<float>(raw) / (1 << _width)) * _scale);
    }

}; // namespace Sensor