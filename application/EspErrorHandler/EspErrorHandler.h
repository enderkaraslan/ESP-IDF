#pragma once

#include "esp_err.h"

class EspErrorHandler
{
private:
    esp_err_t _status;

public:
    explicit EspErrorHandler(esp_err_t status = ESP_OK);

    EspErrorHandler& operator|=(esp_err_t new_status);

    esp_err_t status() const;
};
