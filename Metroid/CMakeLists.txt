project(Metroid)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/Transition.cpp
        src/Transition.h
        sprites/samus_aran.h achtergrond/AchtergrondTransition.h src/Metroid.cpp src/Metroid.h achtergrond/AchtergrondLvl1.h src/ball.h sprites/projectiel.h src/Bullet.cpp src/Bullet.h src/Mario.cpp src/Mario.h src/Level1.cpp src/Level1.h src/MarioBullet.cpp src/MarioBullet.h achtergrond/MapdataLvl1.h src/DeadScene.cpp src/DeadScene.h sound/SoundDeath.h sound/SoundIntro.h src/IntroScene.cpp src/IntroScene.h achtergrond/achtergrondIntro.h src/VictoryScene.cpp src/VictoryScene.h achtergrond/achtergrondVictory.h sound/SoundVictory.h sound/SoundFX.h sound/SoundFX2.h achtergrond/MapdataLvl2.h src/Level2.cpp src/Level2.h achtergrond/AchtergrondLvl2.h)



target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba)