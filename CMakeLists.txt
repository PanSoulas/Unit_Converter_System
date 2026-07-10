cmake_minimum_required(VERSION 3.10)
project(UnitConverter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)

include_directories(include)

add_executable(UnitConverter
    main.cpp
    src/ConverterSystem.cpp
    src/TemperatureSystem.cpp
    src/LengthSystem.cpp
    src/MassSystem.cpp
    src/AngleSystem.cpp
    src/PressureSystem.cpp
    src/SpeedSystem.cpp
    src/EnergySystem.cpp
    src/FrequencySystem.cpp
)
