#pragma once

#include "driver/uart.h"
#include "EspErrorHandler.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include <cstring>

namespace Serial_comms
{

class Uart
{
private:
    const uart_port_t _uart_num;
    uart_config_t _uart_config;
    const int uart_buffer_size = (1024 * 2);
    QueueHandle_t uart_queue;

    
public:
    // Constructor
    Uart(const uart_port_t uart_num = UART_NUM_0, 
                   const uart_config_t& uart_config = {
                       .baud_rate = 115200,
                       .data_bits = UART_DATA_8_BITS,
                       .parity = UART_PARITY_DISABLE, // UART haberleşmesinde hata kontrolü sağlamak için kullanılan bir bittir.	
                       .stop_bits = UART_STOP_BITS_1, // Stop bitleri, gönderilen verinin sonunda iletişimi sonlandırmak için kullanılır.
                       .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
                       .rx_flow_ctrl_thresh = 122, // RX tamponundaki veri miktarı bu eşik değere ulaştığında RTS sinyalini tetikleyen bir parametredir.
                    })
        : _uart_num{uart_num}, 
          _uart_config{uart_config}
    {
    }

    // UART'ı başlatan init fonksiyonu
    esp_err_t init();

    // UART üzerinden veri gönderme fonksiyonu
    esp_err_t write(const char* data, size_t length);

    // UART üzerinden kesme sinyali ile veri gönderme
    esp_err_t write_with_break(const char* data, size_t length, int brk_len = 100);

    //
    esp_err_t write_chars(const char* data, uint32_t length);

    //
    esp_err_t wait_tx(TickType_t timeout = portMAX_DELAY);

    // UART üzerinden veri okuma fonksiyonu
    esp_err_t read(char* buffer, size_t length, TickType_t timeout = pdMS_TO_TICKS(1000));

    // UART sürücüsünü kaldırma fonksiyonu
    esp_err_t deinit();



    ~Uart();

}; // class Uart

} // namespace Serial_comms