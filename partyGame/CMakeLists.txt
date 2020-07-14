project(partyGame)

add_executable(${PROJECT_NAME}.elf


        src/main.cpp
        src/Game/Bord.cpp
        src/Game/Bord.h
        src/Game/Game.cpp
        src/Game/Game.h
        src/Game/Speler.cpp
        src/Game/Speler.h

        screens/MainMenuScreen.cpp
        screens/MainMenuScreen.h
        screens/AboutScreen.cpp
        screens/AboutScreen.h
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
        img/hoofdpersonage.c
        img/hoofdpersonage.h

        backgrounds/Tiles8x8.c
        backgrounds/Tiles8x8.h
        backgrounds/eerste7x7Map.h

        src/Game/Game.cpp src/Game/Game.h src/Game/Speler.cpp src/Game/Speler.h src/Game/Bord.cpp src/Game/Bord.h screens/GameScreen.cpp screens/GameScreen.h screens/VangspelScreen.cpp screens/VangspelScreen.h src/Minigame1/Minigame1.cpp src/Minigame1/Minigame1.h src/Minigame1/VallendVoorwerp.cpp src/Minigame1/VallendVoorwerp.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )