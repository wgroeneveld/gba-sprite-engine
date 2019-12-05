

#include <libgba-sprite-engine/gba_engine.h>
#include "Level1_scene.h"

/**
 * shared palette extracted from grit
 * ./../grit piskel.png piskel2.png kul.png -ftc -pS -gB8 -O shared.c
 * assumes 8bpp sprites
 */
int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    Level1_scene* level1Scene = new Level1_scene(engine);
    engine->setScene(level1Scene);

    while (true) {
        engine->update();
        engine->delay(1000);
    }

    return 0;
}