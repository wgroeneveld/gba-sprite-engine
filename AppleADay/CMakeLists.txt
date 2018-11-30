project(apple_a_day)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/start_scene.cpp
        src/start_scene.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )