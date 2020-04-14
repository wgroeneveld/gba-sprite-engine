project(partyGame)

add_executable(${PROJECT_NAME}.elf


        src/main.cpp
        src/Bord.cpp
        src/Bord.h
        src/Game.cpp
        src/Game.h
        src/Speler.cpp
        src/Speler.h
        src/Vakje.cpp
        src/Vakje.h
        src/controller.cpp
        src/controller.h

        screens/MainMenuScreen.cpp
        screens/MainMenuScreen.h
        screens/AboutScreen.cpp
        screens/AboutScreen.h
        screens/boardScreen.cpp
        screens/boardScreen.h
        screens/GameScreen.cpp
        screens/GameScreen.h

        img/minion_image.h
        img/basketballAnimated.c
        img/basketballAnimated.h
        img/stickmanAnimated.c
        img/stickmanAnimated.h
        img/shared.c
        img/shared.h
        img/speler1.c
        img/speler1.h
        img/spelerAI.c
        img/spelerAI.h

        backgrounds/map.h
        backgrounds/tiles.h
        backgrounds/tiles.c

        backgrounds/testtest2.h src/Game.cpp src/Game.h src/Vakje.cpp src/Vakje.h src/Speler.cpp src/Speler.h src/Bord.cpp src/Bord.h screens/GameScreen.cpp screens/GameScreen.h src/controller.cpp src/controller.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )