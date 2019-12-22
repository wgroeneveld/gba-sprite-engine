cmake_minimum_required(VERSION 3.15)
project(avatar_the_last_airbender)

set(CMAKE_CXX_STANDARD 14)

add_executable(avatar_the_last_airbender.elf
        src/main.cpp
        src/Titlescreen_scene.cpp
        src/Titlescreen_scene.h
        src/Level1_scene.cpp
        src/Level1_scene.h
        src/background_title/titlescreen.h
        src/background_game/background_earth_data.h
        src/background_game/background_earth_tilemap.h
        src/background_game/background_water.h
        src/background_game/white_background.h
        src/enemy/enemy_sprite.h
        )


target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)


add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
