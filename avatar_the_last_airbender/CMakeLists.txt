cmake_minimum_required(VERSION 3.15)
project(avatar_the_last_airbender)

set(CMAKE_CXX_STANDARD 14)

add_executable(avatar_the_last_airbender.elf
        src/main.cpp
        src/Scene_Start.cpp
        src/Scene_Start.h
        src/Scene_Level1.cpp
        src/Scene_Level1.h
        src/AirBall.cpp
        src/AirBall.h
        src/data/background_game/backgroundGround/background13_set.h
        src/data/background_game/backgroundGround/background1_map.h
        src/data/background_game/backgroundSea/background2_set.h
        src/data/background_game/backgroundSea/background2_map.h
        src/data/background_game/backgroundSun/background3_map.h
        src/data/background_game/background_pal.h
        src/data/background_title/titlescreen_newgame.h
        src/data/sprites/sprite_aangdown.h
        src/data/sprites/sprite_aangup.h
        src/data/sprites/sprite_enemy.h
        src/data/sprites/sprite_airball.h
        src/data/sprites/sprite_pal.h
        src/Enemy.cpp src/Enemy.h)


target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)


add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
