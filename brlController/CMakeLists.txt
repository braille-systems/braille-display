cmake_minimum_required(VERSION 3.14)
project(brlController)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(brailleDisplay)
include_directories(sensors)
include_directories(serial)
include_directories(speaker)
include_directories(debug)

add_executable(brlController
        speaker/pitches.h
        speaker/speaker.h
        sensors/button.h
        sensors/controlHub.h
        sensors/joystick.h
        serial/brlSerial.h
        brailleDisplay/brailleDisplay.h
        device.h
        main.h
        debug/main.cpp)
