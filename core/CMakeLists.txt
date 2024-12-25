<<<<<<< HEAD
set(SOURCES ./Src/main.cpp)

idf_component_register(SRCS ${SOURCES}
                        INCLUDE_DIRS . Inc
                        REQUIRES freertos 
                                    esp_common 
                                    Gpio
                                    Wifi
                                    esp_event
                                    nvs_flash
                                    DistanceSensor
                                    Potentiometer
                                    Uart)
=======
set(SOURCES ./Src/main.cpp)

idf_component_register(SRCS ${SOURCES}
                        INCLUDE_DIRS . Inc
                        REQUIRES freertos 
                                    esp_common 
                                    Gpio
                                    Wifi
                                    esp_event
                                    nvs_flash)
>>>>>>> 8bdcc15964fc771d3f9424f95387928eb9075170
