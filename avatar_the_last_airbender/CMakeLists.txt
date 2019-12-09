cmake_minimum_required(VERSION 3.15)
project(avatar_the_last_airbender)

set(CMAKE_CXX_STANDARD 14)

add_executable(avatar_the_last_airbender.elf
        src/titlescreen.h
        src/main.cpp
        src/Titlescreen_scene.cpp
        src/Titlescreen_scene.h
        src/Level1_scene.cpp
        src/Level1_scene.h
        src/aang_jump2.h
        src/white_background.h)


target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)


add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
