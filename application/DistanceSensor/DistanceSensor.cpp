#include "DistanceSensor.h"
#define SOUND_SPEED 34300.0 // cm/s
#define ROUNDTRIP (SOUND_SPEED / 2.0) // cm/μs
namespace Sensor
{
    [[nodiscard]] esp_err_t DistanceSensor::init(void)
    {
        EspErrorHandler handler;
        handler |= _trig_pin.init();
        handler |= _echo_pin.init();
        return handler.status();
    }

float DistanceSensor::get_distance(void)
{
    // Trigger pin için darbe gönder
    _trig_pin.set(false);
    esp_rom_delay_us(2);
    _trig_pin.set(true);
    esp_rom_delay_us(10);
    _trig_pin.set(false);

    // Yankı bekleme süresini başlat
    uint32_t start_time = esp_timer_get_time();

    // Yankı sinyalinin başlamasını bekle (LOW -> HIGH)
    while (_echo_pin.state() == false) 
    {
        if (esp_timer_get_time() - start_time > 30000 ) 
        {
            return -1.0f; // Zaman aşımı, sensör hatası
        }
    }

    // Yankı süresini ölç (HIGH sinyal süresi)
    uint32_t echo_start = esp_timer_get_time();
    while (_echo_pin.state() == true) 
    {
        if (esp_timer_get_time() - echo_start > 30000 ) 
        {
            return -1.0f; // Zaman aşımı, sensör hatası
        }
    }
    uint32_t echo_end = esp_timer_get_time();

    // Mesafeyi hesapla
    float distance = (echo_end - echo_start) / ROUNDTRIP;

    // Mantıklı mesafe değerlerini kontrol et (ör. 2 cm - 400 cm aralığı)
    if (distance < 2.0f || distance > 400.0f) 
    {
        return -1.0f; // Geçersiz mesafe
    }

    return distance;
}
}; // namespace Sensor