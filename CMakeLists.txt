cmake_minimum_required(VERSION 3.14)

project(SimpleFOC_ZJU LANGUAGES CXX)

option(ZJUNLICT_DEBUG "debug output." ON)
option(USE_RPI "use Raspberry Pi as mcu." ON)
option(USE_ARDUINO_IDE "use ArduinoIDE." OFF)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src/common
    ${CMAKE_CURRENT_SOURCE_DIR}/src/common/base_classes
    ${CMAKE_CURRENT_SOURCE_DIR}/src/communication
    ${CMAKE_CURRENT_SOURCE_DIR}/src/current_sense
    ${CMAKE_CURRENT_SOURCE_DIR}/src/current_sense/hardware_specific
    ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers
    ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/hardware_specific
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sensors
)
set(cpp_files ${cpp_files}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/BLDCMotor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/common/base_classes/CurrentSense.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/common/base_classes/FOCMotor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/common/base_classes/Sensor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/common/foc_utils.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/common/lowpass_filter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/common/pid.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/common/time_utils.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/communication/Commander.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/communication/StepDirListener.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/current_sense/InlineCurrentSense.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/current_sense/LowsideCurrentSense.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/BLDCDriver3PWM.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/BLDCDriver6PWM.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/hardware_specific/atmega2560_mcu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/hardware_specific/atmega328_mcu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/hardware_specific/atmega32u4_mcu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/hardware_specific/due_mcu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/hardware_specific/esp32_mcu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/hardware_specific/esp8266_mcu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/hardware_specific/generic_mcu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/hardware_specific/portenta_h7_mcu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/hardware_specific/rp2040_mcu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/hardware_specific/samd21_mcu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/hardware_specific/samd51_mcu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/hardware_specific/samd_mcu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/hardware_specific/stm32_mcu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/hardware_specific/teensy_mcu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/StepperDriver2PWM.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/StepperDriver4PWM.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sensors/Encoder.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sensors/HallSensor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sensors/MagneticSensorAnalog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sensors/MagneticSensorI2C.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sensors/MagneticSensorPWM.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sensors/MagneticSensorSPI.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/StepperMotor.cpp
)
if(USE_RPI)
    set(cpp_files ${cpp_files}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/current_sense/hardware_specific/rpi_mcu.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/interface/hardware_interface.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/interface/Stream.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/interface/Arduino.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/interface/Print.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/interface/WString.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/interface/libraries/Wire/src/Wire.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/interface/libraries/Wire/src/twi.c
        )
    include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/src/interface
        ${CMAKE_CURRENT_SOURCE_DIR}/src/interface/libraries/Wire/src
        ${CMAKE_CURRENT_SOURCE_DIR}/src/interface/libraries/SPI/src
    )
endif()

set(srcs
    ${cpp_files}    
    )
set(target_lib SimpleFOC_ZJU)
add_library(${target_lib} SHARED ${srcs})
