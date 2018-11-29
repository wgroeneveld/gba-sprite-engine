project(arkanoid)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/pats.h
        src/arkanoid_game_scene.cpp
        src/arkanoid_game_scene.h src/spritedata.h src/dead.h src/SplashScreen.cpp src/SplashScreen.h src/splashimage.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
