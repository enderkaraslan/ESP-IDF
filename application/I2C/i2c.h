#pragma once

#include "driver/i2c.h"
#include "EspErrorHandler.h"
#include <vector>
#include "esp_log.h"

namespace I2C
{

class I2CBase
{
protected:
    const i2c_port_t _port;
    const i2c_config_t _config;

public:
    constexpr I2CBase(const i2c_port_t port, const i2c_config_t& config) :
        _port{port},
        _config{config}
    {
    }

    esp_err_t init()
    {
        esp_err_t err;
        err = i2c_param_config(_port, &_config);
        if (err != ESP_OK)
        {
            ESP_LOGE("I2C", "Failed to configure I2C parameters: %s", esp_err_to_name(err));
            return err;
        }

        err = i2c_driver_install(_port, _config.mode, 0, 0, 0);
        if (err != ESP_OK)
        {
            ESP_LOGE("I2C", "Failed to install I2C driver: %s", esp_err_to_name(err));
        }
        return err;
    }

    virtual ~I2CBase()
    {
        esp_err_t err = i2c_driver_delete(_port);
        if (err != ESP_OK)
        {
            ESP_LOGE("I2C", "Failed to delete I2C driver: %s", esp_err_to_name(err));
        }
    }
};

class I2CMaster : public I2CBase
{
public:
    constexpr I2CMaster(const i2c_port_t port, const gpio_num_t sda_pin, const gpio_num_t scl_pin, const uint32_t freq_hz) :
        I2CBase{port,
                i2c_config_t{
                    .mode = I2C_MODE_MASTER,
                    .sda_io_num = sda_pin,
                    .scl_io_num = scl_pin,
                    .sda_pullup_en = GPIO_PULLUP_ENABLE,
                    .scl_pullup_en = GPIO_PULLUP_ENABLE,
                    .master = {.clk_speed = freq_hz},
                    .clk_flags = 0,
                }}
    {
    }

    esp_err_t write(const uint8_t device_address, const std::vector<uint8_t>& data, const bool ack_check = true)
    {
        i2c_cmd_handle_t cmd = i2c_cmd_link_create();
        if (!cmd)
        {
            ESP_LOGE("I2C", "Failed to create I2C command link.");
            return ESP_FAIL;
        }

        i2c_master_start(cmd);
        i2c_master_write_byte(cmd, (device_address << 1) | I2C_MASTER_WRITE, ack_check);
        i2c_master_write(cmd, data.data(), data.size(), ack_check);
        i2c_master_stop(cmd);

        esp_err_t err = i2c_master_cmd_begin(_port, cmd, pdMS_TO_TICKS(1000));
        if (err != ESP_OK)
        {
            ESP_LOGE("I2C", "Failed to write to device: %s", esp_err_to_name(err));
        }

        i2c_cmd_link_delete(cmd);
        return err;
    }

    esp_err_t read(const uint8_t device_address, std::vector<uint8_t>& data, const bool ack_check = true)
    {
        i2c_cmd_handle_t cmd = i2c_cmd_link_create();
        if (!cmd)
        {
            ESP_LOGE("I2C", "Failed to create I2C command link.");
            return ESP_FAIL;
        }

        i2c_master_start(cmd);
        i2c_master_write_byte(cmd, (device_address << 1) | I2C_MASTER_READ, ack_check);
        i2c_master_read(cmd, data.data(), data.size(), I2C_MASTER_LAST_NACK);
        i2c_master_stop(cmd);

        esp_err_t err = i2c_master_cmd_begin(_port, cmd, pdMS_TO_TICKS(1000));
        if (err != ESP_OK)
        {
            ESP_LOGE("I2C", "Failed to read from device: %s", esp_err_to_name(err));
        }

        i2c_cmd_link_delete(cmd);
        return err;
    }
};

class I2CSlave : public I2CBase
{
public:
    constexpr I2CSlave(const i2c_port_t port, const gpio_num_t sda_pin, const gpio_num_t scl_pin, const uint8_t slave_address) :
        I2CBase{port,
                i2c_config_t{
                    .mode = I2C_MODE_SLAVE,
                    .sda_io_num = sda_pin,
                    .scl_io_num = scl_pin,
                    .sda_pullup_en = GPIO_PULLUP_ENABLE,
                    .scl_pullup_en = GPIO_PULLUP_ENABLE,
                    .slave = {.addr_10bit_en = 0, .slave_addr = slave_address},
                    .clk_flags = 0,
                }}
    {
    }

    esp_err_t read(std::vector<uint8_t>& data)
    {
        int size = i2c_slave_read_buffer(_port, data.data(), data.size(), pdMS_TO_TICKS(1000));
        if (size < 0)
        {
            ESP_LOGE("I2C", "Failed to read from I2C slave buffer.");
            return ESP_FAIL;
        }
        return ESP_OK;
    }

    esp_err_t write(const std::vector<uint8_t>& data)
    {
        int size = i2c_slave_write_buffer(_port, data.data(), data.size(), pdMS_TO_TICKS(1000));
        if (size < 0)
        {
            ESP_LOGE("I2C", "Failed to write to I2C slave buffer.");
            return ESP_FAIL;
        }
        return ESP_OK;
    }
};

} // namespace I2C
