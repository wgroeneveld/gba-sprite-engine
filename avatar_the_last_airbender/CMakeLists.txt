cmake_minimum_required(VERSION 3.15)
project(avatar_the_last_airbender)

set(CMAKE_CXX_STANDARD 14)

add_executable(avatar_the_last_airbender.elf
        src/main.cpp
        src/Scene_Start.cpp
        src/Scene_Start.h
        src/Scene_Level1.cpp
        src/Scene_Level1.h
        src/Scene_Level2.cpp
        src/Scene_Level2.h
        src/AirBall.cpp
        src/AirBall.h
        src/background_game/backgroundGround/background13_set.h
        src/background_game/backgroundGround/background1_map.h
        src/background_game/backgroundSea/background2_set.h
        src/background_game/backgroundSea/background2_map.h
        src/background_game/backgroundSun/background3_map.h
        src/background_game/background_pal.h
        src/background_title/titlescreen_newgame.h
        src/background_title/titlescreen_options.h
        src/background_title/titlescreen_pal.h
        src/sprites/sprite_aang.h
        src/sprites/sprite_enemy.h
        src/sprites/sprite_airball.h
        src/sprites/sprite_pal.h
        )


target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)


add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
