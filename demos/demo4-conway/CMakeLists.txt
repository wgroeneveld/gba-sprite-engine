project(conway)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp src/ConwayScene.cpp src/ConwayScene.h
        src/NaiveConwayScene.cpp src/NaiveConwayScene.h src/bg.h src/ConwaySeeder.cpp src/ConwaySeeder.h src/ActiveTrackingConwayScene.cpp src/ActiveTrackingConwayScene.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
