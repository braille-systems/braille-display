cmake_minimum_required(VERSION 3.14)
project(brlController)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(brailleDisplay)
include_directories(sensors)
include_directories(serial)
include_directories(speaker)

add_executable(brlController
        sensors/button.cpp
        sensors/button.h
        sensors/controlHub.h
        sensors/joystick.h
        serial/brlSerial.cpp
        serial/brlSerial.h
        device.cpp
        device.h main.cpp speaker/speaker.cpp speaker/speaker.h speaker/pitches.h sensors/controlHub.cpp brailleDisplay/brailleDisplay.cpp brailleDisplay/brailleDisplay.h)
