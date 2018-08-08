project(flyingstuff)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/sample_start_scene.cpp
        src/sample_start_scene.h
        src/lama.h
        src/sample_sound.h
        src/kul.h
        src/flying_stuff_scene.cpp
        src/flying_stuff_scene.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
