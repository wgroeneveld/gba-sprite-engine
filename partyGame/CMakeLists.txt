project(partyGame)

add_executable(${PROJECT_NAME}.elf


        src/main.cpp
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
        backgrounds/gras.c
        backgrounds/gras.h
        backgrounds/grasBackground.h
        backgrounds/gunshot.h

        backgrounds/witspook1.c
        backgrounds/witspook1.h
        backgrounds/witspook2.c
        backgrounds/witspook2.h
        backgrounds/dobbelsteen.c
        backgrounds/dobbelsteen.h

        backgrounds/GameScreen/wit_spook_1.h
        backgrounds/GameScreen/wit_spook_1.c
        backgrounds/GameScreen/wit_spook_2.h
        backgrounds/GameScreen/wit_spook_2.c
        backgrounds/GameScreen/red_stone_with_border.h
        backgrounds/GameScreen/red_stone_with_border.c
        backgrounds/GameScreen/green_stone_with_border.h
        backgrounds/GameScreen/green_stone_with_border.c
        backgrounds/GameScreen/blue_stone_with_border.h
        backgrounds/GameScreen/blue_stone_with_border.c
        backgrounds/GameScreen/shared10.h
        backgrounds/GameScreen/shared10.c

        backgrounds/MainMenu/pijl.c
        backgrounds/MainMenu/pijl.h

        backgrounds/Minigame/sharedMinigame.h
        backgrounds/Minigame/sharedMinigame.c
        backgrounds/Minigame/box.h
        backgrounds/Minigame/box.c
        backgrounds/Minigame/redEnemy.h
        backgrounds/Minigame/redEnemy.c
        backgrounds/Minigame/greenEnemy.h
        backgrounds/Minigame/greenEnemy.c
        backgrounds/Minigame/blueEnemy.h
        backgrounds/Minigame/blueEnemy.c

        src/Game/Game.cpp src/Game/Game.h src/Game/Speler.cpp src/Game/Speler.h screens/GameScreen.cpp screens/GameScreen.h src/Minigame1/Minigame1.cpp src/Minigame1/Minigame1.h src/Minigame2/Minigame2.cpp src/Minigame2/Minigame2.h screens/MinigameScreen.cpp screens/MinigameScreen.h screens/EndScreen.cpp screens/EndScreen.h screens/PlayerSelectScreen.cpp screens/PlayerSelectScreen.h src/Minigame.cpp src/Minigame.h src/Minigame3.cpp src/Minigame3.h screens/Minigame1Screen.cpp screens/Minigame1Screen.h screens/Minigame2Screen.cpp screens/Minigame2Screen.h screens/Minigame3Screen.cpp screens/Minigame3Screen.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )