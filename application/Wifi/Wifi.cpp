#include "wifi.h"

namespace WIFI
{
//std::atomic_bool Wifi::first_call{false};

std::mutex Wifi::first_call_mutx;
bool Wifi::first_call{false};

char Wifi::mac_addr_cstr[]{};

esp_err_t Wifi::_get_mac(void)
{
    uint8_t mac_byte_buffer[6]{};

    const esp_err_t status{esp_efuse_mac_get_default(mac_byte_buffer)};
    
    if (ESP_OK == status)
    {
        snprintf(mac_addr_cstr , sizeof(mac_addr_cstr), 
            "%02X%02X%02X%02X%02X%02X",
            mac_byte_buffer[0], 
            mac_byte_buffer[1], 
            mac_byte_buffer[2],
            mac_byte_buffer[3], 
            mac_byte_buffer[4], 
            mac_byte_buffer[5]);
    }

    return status;
}   


} //namespace WIFI