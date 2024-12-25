#pragma once

#include "esp_wifi.h"
#include "esp_mac.h"
#include "esp_event.h"
#include "esp_log.h"

#include <algorithm>
#include <mutex>

#include <cstring>


namespace WIFI
{

class Wifi
{

    constexpr static const char* ssid{"MyWifiSsid"};
    constexpr static const char* password{"MyWifiPassword"};

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
    ~Wifi(void)                     = default;	
    Wifi(const Wifi&)               = default;
    Wifi(Wifi&&)                    = default;
    Wifi& operator=(const Wifi&)    = default;
    Wifi& operator=(Wifi&&)         = default;

    esp_err_t init(void);           ///< set everything up
    esp_err_t begin(void);          ///< start Wifi, connect, etc...

    state_e get_state(void);
    
    constexpr static const char* get_mac(void) 
        { return mac_addr_cstr; }

private:
    static esp_err_t _init(void);
    static wifi_init_config_t wifi_init_config;
    static wifi_config_t wifi_config;

    void state_machine(void); 
    static state_e _state;           ///< current state

    // Get the MAC from the API and convert to ASCII HEX
    static esp_err_t _get_mac(void);

    static char mac_addr_cstr[13];  ///< buffer to hold mac address as cstring
    static std::mutex init_mutx;    ///< Initialisation mutex

    

}; // class WIFI
 
} // namespace WIFI