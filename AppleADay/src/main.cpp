//
// Created by Jonas Lommelen on 30/11/2018.
//


#include <libgba-sprite-engine/gba_engine.h>
#include "start_scene.h"

int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    StartScene* startScene = new StartScene(engine);
    engine->setScene(startScene);

    while (true) {
        engine->update();
        engine->delay(1000);
    }

    return 0;
}