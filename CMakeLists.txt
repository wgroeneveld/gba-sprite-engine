cmake_minimum_required(VERSION 3.12)

# use the GBA cross-compiler.
# WARNING: CMAKE_AR and RANLIB didn't use find_program() to scan the PATH yet.
# If using CMake < 3.12, consider using an absolute path. https://gitlab.kitware.com/cmake/cmake/merge_requests/1720
SET(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_GENERATOR "Unix Makefiles")
SET(CMAKE_C_COMPILER    arm-none-eabi-gcc)
SET(CMAKE_CXX_COMPILER arm-none-eabi-g++)
SET(CMAKE_OBJCOPY arm-none-eabi-objcopy)
SET(CMAKE_AR arm-none-eabi-ar CACHE FILEPATH "Archiver")
SET(CMAKE_RANLIB arm-none-eabi-ranlib)

SET(BASE_CMAKE_LINK_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS "${BASE_CMAKE_LINK_FLAGS} -mthumb-interwork -mthumb -specs=gba.specs")

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-narrowing")
set(CMAKE_VERBOSE_MAKEFILE on)

project(gba-sprite-engine-project VERSION 0.1 LANGUAGES CXX)

# Must use GNUInstallDirs to install libraries into correct locations on all platforms.
include(GNUInstallDirs)

add_subdirectory(engine)

# this should be a part of the engine CMakeLists.txt file but cross-compiling and gtest doesn't work
add_subdirectory(test)

add_subdirectory(demos/demo1-basicfeatures)
add_subdirectory(demos/demo2-arkanoid)
add_subdirectory(demos/demo3-foodthrowing)
add_subdirectory(demos/demo4-conway)