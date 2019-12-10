project(game)

add_executable(${PROJECT_NAME}.elf
        game/ChooseCharachter_Screen.cpp
        game/ChooseCharachter_Screen.h
        game/Game.cpp
        game/Game.h
        game/main.cpp
        game/Start_Screen.cpp
        game/Start_Screen.h
        game/Sprites_Data.h

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
