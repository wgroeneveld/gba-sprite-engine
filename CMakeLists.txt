cmake_minimum_required(VERSION 3.10)

SET(CMAKE_C_COMPILER arm-none-eabi-gcc)
SET(CMAKE_CXX_COMPILER arm-none-eabi-g++)
SET(CMAKE_OBJCOPY arm-none-eabi-objcopy)
SET(BASE_CMAKE_LINK_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS "${BASE_CMAKE_LINK_FLAGS} -mthumb-interwork -mthumb -specs=gba.specs")

project(gba-sprite-engine)
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-narrowing")
set(CMAKE_VERBOSE_MAKEFILE on)

include_directories(src)
include_directories(test)
add_subdirectory(src)
add_subdirectory(test)
