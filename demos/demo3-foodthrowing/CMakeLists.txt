project(foodthrowing)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/food_scene.cpp
        src/food_scene.h
        src/avatar.h src/bullet_data.h src/bullet.cpp src/bullet.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
