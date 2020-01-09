project(Metroid)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/menu.cpp
        src/menu.h
        src/sample_sound.h
        src/samus_aran.h src/achtergrond.h src/achtergrond2.h src/Metroid.cpp src/Metroid.h src/achtergrond3.h src/ball.h src/projectiel.h src/Bullet.cpp src/Bullet.h src/Mario.cpp src/Mario.h src/Level1.cpp src/Level1.h src/MarioBullet.cpp src/MarioBullet.h src/test.h src/DeadScene.cpp src/DeadScene.h src/SoundDeath.h src/SoundIntro.h src/IntroScene.cpp src/IntroScene.h src/achtergrondIntro.h src/VictoryScene.cpp src/VictoryScene.h src/achtergrondVictory.h src/SoundVictory.h src/SoundFX.h src/SoundFX2.h src/MapdataLvl2.h src/Level2.cpp src/Level2.h src/achtergrondDataLvl2.h src/OvergangScene1.cpp src/OvergangScene1.h)



target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba)