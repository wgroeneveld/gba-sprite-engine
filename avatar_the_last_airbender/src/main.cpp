#include <libgba-sprite-engine/gba_engine.h>

#include "Scene_Start.h"

int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    Scene_Start* scene_start = new Scene_Start(engine);
    engine->setScene(scene_start);

    while (true) {
        engine->update();
        engine->delay(1000);
    }

    return 0;
}