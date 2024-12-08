#pragma once

#include "esp_wifi.h"
#include "esp_mac.h"

namespace WIFI
{

class Wifi
{

public:
    enum class state_e
    {
        NOT_INITIALISED,
        INITIALISED,
        WAITING_FOR_CREDENTIALS,
        READY_TO_CONNECT,
        CONNECTING,
        WAITING_FOR_IP,
        CONNECTED,
        DISCONNECTED,
        ERROR
    };

    Wifi(void)
    {
        if (ESP_OK != _get_mac()) abort();
    }

    esp_err_t init(void); // set everything up
    esp_err_t begin(void); //start Wifi, connect, etc...

    state_e get_state(void);
    const char* get_mac(void) 
        { return mac_addr_cstr; }

private:
    void state_machine(void); 

    esp_err_t _get_mac(void);
    static char mac_addr_cstr[13];

}; // class WIFI

} // namespace WIFI