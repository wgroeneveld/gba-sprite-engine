//
// Created by Wouter Groeneveld on 08/08/18.
//

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>

#include "arkanoid_game_scene.h"
#include "SplashScreen.h"

int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    auto scene = new SplashScreen(engine);
    engine->setScene(scene);

    while (true) {
        engine->update();
    }

    return 0;
}