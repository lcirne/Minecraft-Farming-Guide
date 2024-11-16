cmake_minimum_required(VERSION 3.29)
project(M3OEP_lcirne)

set(CMAKE_CXX_STANDARD 17)

add_executable(M3OEP_lcirne
        Main.cpp
        MinecraftFarmingGuide.cpp
        Crop.cpp
        Farm.cpp)

add_executable(TestingSuite
        Testing.cpp
        MinecraftFarmingGuide.cpp
        Crop.cpp
        Farm.cpp)