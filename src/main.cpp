#include <engine/Scene.h>
#include <engine/gba_engine.h>
#include <engine/background/text.h>
#include <engine/background/text_stream.h>
#include <engine/palette_manager.h>
#include <engine/allocator.h>

#include "kul.h"
#include "sample_start_scene.h"
#include "flying_stuff_scene.h"

/**
 * shared palette extracted from grit
 * ./../grit piskel.png piskel2.png kul.png -ftc -pS -gB8 -O shared.c
 * assumes 8bpp sprites
 */
int main() {
    GBAEngine engine;

    SampleStartScene startScene;
    engine.setScene(startScene);

    while (true) {
        engine.update();
        engine.delay(1000);
    }

    return 0;
}