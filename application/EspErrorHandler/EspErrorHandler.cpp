// EspErrorHandler.cpp
#include "EspErrorHandler.h"

EspErrorHandler::EspErrorHandler(esp_err_t status) : _status(status) {}

EspErrorHandler& EspErrorHandler::operator|=(esp_err_t new_status)
{
    if (_status == ESP_OK)
    {
        _status = new_status;
    }
    return *this;
}

esp_err_t EspErrorHandler::status() const
{
    return _status;
}
