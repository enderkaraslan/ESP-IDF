#pragma once

#include "esp_wifi.h"
#include "esp_mac.h"

#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#define pdSECOND pdMS_TO_TICKS(1000)

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

    Wifi(void);

    esp_err_t init(void); // set everything up
    esp_err_t begin(void); //start Wifi, connect, etc...

    state_e get_state(void);
    const char* get_mac(void) 
        { return mac_addr_cstr; }

private:
    void state_machine(void); 

    esp_err_t _get_mac(void);
    static char mac_addr_cstr[13];

    static SemaphoreHandle_t first_call_mutx; 
    static StaticSemaphore_t first_call_mutx_buffer;
    static bool first_call;

}; // class WIFI

} // namespace WIFI