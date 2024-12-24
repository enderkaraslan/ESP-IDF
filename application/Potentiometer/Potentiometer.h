#pragma once


#include "driver/adc.h"
#include "EspErrorHandler.h"

namespace Sensor {

class Potentiometer {
private:
    const adc1_channel_t _channel;       // ADC Channel
    const adc_bits_width_t _width;       // ADC Resolution
    const adc_atten_t _attenuation;      // ADC Attenuation
    const uint8_t _scale ;                   // Scale factor

public:
    // Constructor
    Potentiometer(
        adc1_channel_t channel = ADC1_CHANNEL_4,
        adc_bits_width_t width = ADC_WIDTH_BIT_12,
        adc_atten_t attenuation = ADC_ATTEN_DB_11,
        uint8_t scale = 100)
        : _channel(channel), _width(width), _attenuation(attenuation), _scale(scale) 
        {

        }

    // Initialize ADC configuration
    esp_err_t init();

    // Read raw ADC value
    int read_raw() const;

    // Calculate scaled value from raw ADC value
    int read_scaled_value() const;

}; // class Potentiometer

} // namespace Sensor