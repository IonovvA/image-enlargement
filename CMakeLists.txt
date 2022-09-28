cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(Image_enlargement)

include(function.cmake)

add_subdirectory(Image)
add_subdirectory(StaticLib)

option(BTEST "build test?" ON)

if(BTEST)
    add_subdirectory(gtest)
    add_subdirectory(test)
endif()
