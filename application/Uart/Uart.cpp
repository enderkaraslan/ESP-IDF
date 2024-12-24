#include "Uart.h"

namespace Serial_comms
{
    esp_err_t Uart::init()
    {
        EspErrorHandler handler;

        handler |= uart_param_config(_uart_num, &_uart_config);
        handler |= uart_set_pin(_uart_num, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
        handler |= uart_driver_install(_uart_num, uart_buffer_size, uart_buffer_size, 10, &uart_queue, ESP_INTR_FLAG_IRAM);
        
        return handler.status();
    }

    esp_err_t Uart::write(const char* data, size_t length)
    {
        EspErrorHandler handler;

        if (data == nullptr || length == 0) 
        {
            return ESP_ERR_INVALID_ARG; 
        }

        
        int bytes_written = uart_write_bytes(_uart_num, data, length);
        if (bytes_written < 0) 
        {
            handler |= ESP_FAIL;
        }

        return handler.status();
    }

    esp_err_t Uart::write_with_break(const char* data, size_t length, int brk_len)
    {
        EspErrorHandler handler;

        if(data == nullptr ||length == 0)
        {
            return ESP_ERR_INVALID_ARG;
        }

        int bytes_written = uart_write_bytes_with_break(_uart_num, data, length, brk_len);

        if(bytes_written < 0)
        {
            handler |= ESP_FAIL;
        }
        
        return handler.status();
    }

    esp_err_t Uart::write_chars(const char* data, uint32_t length)
    {
        EspErrorHandler handler;

        if(data == nullptr || length == 0)
        {
            return ESP_ERR_INVALID_ARG;
        }

        int bytes_written = uart_tx_chars(_uart_num, data, length);

        if(bytes_written < 0)
        {
            handler |= ESP_FAIL;
        }

        return handler.status();
    }

    esp_err_t Uart::wait_tx(TickType_t timeout)
    {
        EspErrorHandler handler;

        handler |= uart_wait_tx_done(_uart_num, timeout);

        return handler.status();
    }

    esp_err_t Uart::read(char* buffer, size_t length, TickType_t timeout)
    {
        EspErrorHandler handler;

        if (buffer == nullptr || length == 0)
        {
            return ESP_ERR_INVALID_ARG;
        }

        
        int bytes_read = uart_read_bytes(_uart_num, buffer, length, timeout);
        if (bytes_read < 0)
        {
            handler |= ESP_FAIL;
        }
        else
        {
            buffer[bytes_read] = '\0'; 
        }

        return handler.status();
    }

    esp_err_t Uart::deinit()
    {
        EspErrorHandler handler;

        handler |= uart_driver_delete(_uart_num);
        return handler.status();
    }

    Uart::~Uart()
    {
        deinit(); 
    }
}