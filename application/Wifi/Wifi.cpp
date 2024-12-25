<<<<<<< HEAD
#include "wifi.h"

namespace WIFI
{

// Wifi statics
char                Wifi::mac_addr_cstr[]{};    ///< Buffer to hold MAC as cstring
std::mutex          Wifi::init_mutx{};          ///< Initialisation mutex




Wifi::Wifi(void)
{
    // Aquire our initialisation mutex to ensure only one
    //   thread (multi-cpu safe) is running this
    //   constructor at once.  No running twice in parallel!
    std::lock_guard<std::mutex> guard(init_mutx);

    // Check if the MAC cstring currently begins with a
    //   nullptr, i.e. is default initialised, not set
    if (!get_mac()[0])
    {
        // Get the MAC and if this fails restart
        if (ESP_OK != _get_mac())
            esp_restart();
    }
    
}

// Get the MAC from the API and convert to ASCII HEX
esp_err_t Wifi::_get_mac(void)
{
    uint8_t mac_byte_buffer[6]{};   ///< Buffer to hold MAC as bytes

    // Get the MAC as bytes from the ESP API
    const esp_err_t status{esp_efuse_mac_get_default(mac_byte_buffer)};
    
    if (ESP_OK == status)
    {
        // Convert the bytes to a cstring and store
        //   in our static buffer as ASCII HEX
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


=======
#include "wifi.h"

namespace WIFI
{

SemaphoreHandle_t Wifi::first_call_mutx{nullptr};
StaticSemaphore_t Wifi::first_call_mutx_buffer{};
bool Wifi::first_call{true};

char Wifi::mac_addr_cstr[]{};

Wifi::Wifi(void)
{

    if (!first_call_mutx) 
    {
        first_call_mutx = xSemaphoreCreateMutexStatic(&first_call_mutx_buffer);
        configASSERT(first_call_mutx);
        
    }
    

    if (first_call && pdPASS == xSemaphoreTake(first_call_mutx, pdSECOND))
    {
        if (ESP_OK != _get_mac()) esp_restart();
        first_call = false;
        configASSERT(pdPASS == xSemaphoreGive(first_call_mutx));

    }
    
}
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


>>>>>>> 8bdcc15964fc771d3f9424f95387928eb9075170
} //namespace WIFI