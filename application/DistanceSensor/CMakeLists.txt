set(SOURCES DistanceSensor.cpp)

idf_component_register(SRCS ${SOURCES}
                        INCLUDE_DIRS . 
                        REQUIRES Gpio
                                    EspErrorHandler
                                    esp_timer)