project(partyGame)

add_executable(${PROJECT_NAME}.elf


        src/main.cpp
        src/Game/Game.cpp
        src/Game/Game.h
        src/Game/Speler.cpp
        src/Game/Speler.h

        screens/OtherScreens/MainMenuScreen.cpp
        screens/OtherScreens/MainMenuScreen.h
        screens/OtherScreens/AboutScreen.cpp
        screens/OtherScreens/AboutScreen.h
        screens/GameScreen/GameScreen.cpp
        screens/GameScreen/GameScreen.h

        backgrounds/Tiles8x8.c
        backgrounds/Tiles8x8.h
        backgrounds/eerste7x7Map.h
        backgrounds/gras.c
        backgrounds/gras.h
        backgrounds/grasBackground.h

        backgrounds/dobbelsteen.c
        backgrounds/dobbelsteen.h

        backgrounds/GameScreen/red_stone_with_border.h
        backgrounds/GameScreen/red_stone_with_border.c
        backgrounds/GameScreen/green_stone_with_border.h
        backgrounds/GameScreen/green_stone_with_border.c
        backgrounds/GameScreen/blue_stone_with_border.h
        backgrounds/GameScreen/blue_stone_with_border.c
        backgrounds/GameScreen/shared10.h
        backgrounds/GameScreen/shared10.c

        img/playerSelect/wit_spook_1.h
        img/playerSelect/wit_spook_2.h
        img/playerSelect/pijl.h
        img/playerSelect/sharedPlayerSelect.h
        img/playerSelect/sharedPlayerSelect.c



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

        Sprites/wit_spook_1.h
        Sprites/wit_spook_1.c
        Sprites/wit_spook_2.h
        Sprites/wit_spook_2.c

        Sprites/redEnemyCenter.h
        Sprites/greenEnemyCenter.h
        Sprites/blueEnemyCenter.h
        Sprites/redEnemyCenter.c
        Sprites/greenEnemyCenter.c
        Sprites/blueEnemyCenter.c

        Sprites/pijl.h
        Sprites/dobbelsteen.h
        Sprites/box.h
        Sprites/pijl.c
        Sprites/dobbelsteen.c
        Sprites/box.c

        Sprites/red_stone_with_border.h
        Sprites/green_stone_with_border.h
        Sprites/blue_stone_with_border.h
        Sprites/red_stone_with_border.c
        Sprites/green_stone_with_border.c
        Sprites/blue_stone_with_border.c

        Sprites/alleKleuren.h
        Sprites/alleKleuren.c

        Sprites/shared.h
        Sprites/shared.c



        src/Game/Game.cpp src/Game/Game.h src/Game/Speler.cpp src/Game/Speler.h screens/GameScreen/GameScreen.cpp screens/GameScreen/GameScreen.h src/Minigames/Minigame1.cpp src/Minigames/Minigame1.h src/Minigames/Minigame2.cpp src/Minigames/Minigame2.h screens/MinigameScreens/MinigameScreen.cpp screens/MinigameScreens/MinigameScreen.h screens/OtherScreens/EndScreen.cpp screens/OtherScreens/EndScreen.h screens/OtherScreens/PlayerSelectScreen.cpp screens/OtherScreens/PlayerSelectScreen.h src/Minigames/Minigame.cpp src/Minigames/Minigame.h src/Minigames/Minigame3.cpp src/Minigames/Minigame3.h screens/MinigameScreens/Minigame1Screen.cpp screens/MinigameScreens/Minigame1Screen.h screens/MinigameScreens/Minigame2Screen.cpp screens/MinigameScreens/Minigame2Screen.h screens/MinigameScreens/Minigame3Screen.cpp screens/MinigameScreens/Minigame3Screen.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )