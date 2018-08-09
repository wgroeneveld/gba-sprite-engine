//
// Created by Wouter Groeneveld on 09/08/18.
//

#include <libgba-sprite-engine/gba_engine.h>
#include "food_scene.h"

int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    auto scene = new FoodScene(engine);
    engine->setScene(scene);

    while (true) {
        engine->update();
    }

    return 0;
}