<<<<<<< HEAD
set(SOURCES Wifi.cpp)

idf_component_register(SRCS ${SOURCES}
                        INCLUDE_DIRS . 
                        REQUIRES esp_wifi 
                                    nvs_flash
                                    esp_event
                                    esp_netif
=======
set(SOURCES Wifi.cpp)

idf_component_register(SRCS ${SOURCES}
                        INCLUDE_DIRS . 
                        REQUIRES esp_wifi 
                                    nvs_flash
                                    esp_event
                                    esp_netif
>>>>>>> 8bdcc15964fc771d3f9424f95387928eb9075170
                                    lwip)