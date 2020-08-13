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

        backgrounds/standard/gras.c
        backgrounds/standard/gras.h
        backgrounds/standard/grasBackground.h
        backgrounds/gameScreen/transparantAndRedMap.h


        sprites/wit_spook_1.h
        sprites/wit_spook_1.c
        sprites/wit_spook_2.h
        sprites/wit_spook_2.c

        sprites/redEnemyCenter.h
        sprites/greenEnemyCenter.h
        sprites/blueEnemyCenter.h
        sprites/redEnemyCenter.c
        sprites/greenEnemyCenter.c
        sprites/blueEnemyCenter.c

        sprites/pijl.h
        sprites/dobbelsteen.h
        sprites/box.h
        sprites/pijl.c
        sprites/dobbelsteen.c
        sprites/box.c

        sprites/red_stone_with_border.h
        sprites/green_stone_with_border.h
        sprites/blue_stone_with_border.h
        sprites/red_stone_with_border.c
        sprites/green_stone_with_border.c
        sprites/blue_stone_with_border.c

        sprites/alleKleuren.h
        sprites/alleKleuren.c

        sprites/shared.h
        sprites/shared.c



        src/Game/Game.cpp src/Game/Game.h src/Game/Speler.cpp src/Game/Speler.h screens/GameScreen/GameScreen.cpp screens/GameScreen/GameScreen.h src/Minigames/Minigame1.cpp src/Minigames/Minigame1.h src/Minigames/Minigame2.cpp src/Minigames/Minigame2.h screens/MinigameScreens/MinigameScreen.cpp screens/MinigameScreens/MinigameScreen.h screens/OtherScreens/EndScreen.cpp screens/OtherScreens/EndScreen.h screens/OtherScreens/PlayerSelectScreen.cpp screens/OtherScreens/PlayerSelectScreen.h src/Minigames/Minigame.cpp src/Minigames/Minigame.h src/Minigames/Minigame3.cpp src/Minigames/Minigame3.h screens/MinigameScreens/Minigame1Screen.cpp screens/MinigameScreens/Minigame1Screen.h screens/MinigameScreens/Minigame2Screen.cpp screens/MinigameScreens/Minigame2Screen.h screens/MinigameScreens/Minigame3Screen.cpp screens/MinigameScreens/Minigame3Screen.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )