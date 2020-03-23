project(partyGame)

add_executable(${PROJECT_NAME}.elf


        main.cpp MainMenu.cpp MainMenu.h About.cpp About.h boardScreen.cpp boardScreen.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )