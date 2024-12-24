set(SOURCES Potentiometer.cpp)

idf_component_register(SRCS ${SOURCES}
                        INCLUDE_DIRS . 
                        REQUIRES EspErrorHandler  
                                    driver
                                    esp_common)