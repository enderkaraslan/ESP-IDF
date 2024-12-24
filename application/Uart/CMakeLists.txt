set(SOURCES Uart.cpp)

idf_component_register(SRCS ${SOURCES}
                        INCLUDE_DIRS . 
                        REQUIRES esp_driver_uart
                                    EspErrorHandler
                                    freertos)