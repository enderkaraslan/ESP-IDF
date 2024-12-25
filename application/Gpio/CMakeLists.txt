<<<<<<< HEAD
set(SOURCES Gpio.cpp)

idf_component_register(SRCS ${SOURCES}
                        INCLUDE_DIRS . 
                        REQUIRES driver
                                    EspErrorHandler)
=======
set(SOURCES Gpio.cpp)

idf_component_register(SRCS ${SOURCES}
                        INCLUDE_DIRS . 
                        REQUIRES driver)
>>>>>>> 8bdcc15964fc771d3f9424f95387928eb9075170
