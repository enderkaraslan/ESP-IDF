#include "main.h"

#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "MAIN"

static Main my_main;

extern "C" void app_main(void)
{
    ESP_ERROR_CHECK(my_main.setup());

    esp_log_level_set("*", LOG_LEVEL_LOCAL);
    
    while (true)
    {
        my_main.run();
    }

}

esp_err_t Main::setup(void)
{
    esp_err_t status{ESP_OK};
    
    status |= led.init();
    status |= button.init();

    ESP_LOGI(LOG_TAG, "Status: %d", status);

    return status;
}

void Main::run(void)
{
        //ESP_LOGI(LOG_TAG, "Hello World!");

        ESP_LOGD(LOG_TAG, "LED on");
        led.set(true);
        ESP_LOGI(LOG_TAG, "BUTTON STATE: %d", button.state());
        vTaskDelay(pdSECOND);
        led.toggle();
        vTaskDelay(pdSECOND);

}