SET(CMAKE_C_COMPILER arm-none-eabi-gcc)
SET(CMAKE_CXX_COMPILER arm-none-eabi-g++)

set_property(SOURCE engine/gba/sin_lut.s PROPERTY LANGUAGE C)
add_executable(${PROJECT_NAME}.elf main.cpp engine/sprites/sprite_manager.cpp engine/sprites/sprite_manager.h engine/gba/tonc_memmap.h engine/gba/tonc_core.h engine/gba/tonc_memdef.h engine/gba/tonc_types.h engine/sprites/sprite.cpp engine/sprites/sprite.h kul.h engine/palette/palette_manager.cpp engine/palette/palette_manager.h engine/palette/combined_palette.cpp engine/palette/combined_palette.h engine/allocator.cpp engine/allocator.h engine/gba/tonc_oam.h engine/gba/tonc_math.h engine/gba/sin_lut.s engine/Scene.cpp engine/Scene.h engine/sprites/sprite_builder.cpp engine/sprites/sprite_builder.h engine/sprites/affine_sprite.cpp engine/sprites/affine_sprite.h flying_stuff_scene.cpp flying_stuff_scene.h engine/gba_engine.cpp engine/gba_engine.h engine/background/text_stream.cpp engine/background/text_stream.h engine/background/background.cpp engine/background/background.h engine/background/text.h sample_start_scene.cpp sample_start_scene.h engine/effects/fade_out_scene.cpp engine/effects/fade_out_scene.h engine/gba/tonc_core_stub.h engine/effects/scene_effect.h lama.h sample_sound.h)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
)
