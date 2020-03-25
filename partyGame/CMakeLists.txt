project(partyGame)

add_executable(${PROJECT_NAME}.elf


        src/main.cpp screens/MainMenuScreen.cpp screens/MainMenuScreen.h screens/AboutScreen.cpp screens/AboutScreen.h screens/boardScreen.cpp screens/boardScreen.h img/minion_image.h testtest.h testtest2.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )