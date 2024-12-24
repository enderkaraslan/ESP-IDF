#include "main.h"

#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "MAIN"

static Main my_main;

extern "C" void app_main(void)
{
    ESP_LOGI(LOG_TAG, "Creating default event loop");
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    ESP_LOGI(LOG_TAG, "Initialising NVS");
    ESP_ERROR_CHECK(nvs_flash_init());
    
    ESP_ERROR_CHECK(my_main.setup());
    
    
    while (true)
    {
        my_main.run();
    }

}

esp_err_t Main::setup(void)
{

    //handler |= led.init();

    const char* my_mac = my_wifi.get_mac();
    ESP_LOGI(LOG_TAG, "Device MAC Address: %s", my_mac);

    ESP_LOGI(LOG_TAG, "Status: %d", handler.status());

    return handler.status();
}

void Main::run(void)
{       


    
    vTaskDelay(pdSECOND);

}