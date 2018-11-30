//
// Created by Wouter Groeneveld on 30/11/18.
//

#include "ConwaySeeder.h"
#include <libgba-sprite-engine/gba_engine.h>

int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    ConwaySeeder* startScene = new ConwaySeeder(engine);
    engine->setScene(startScene);

    while (true) {
        engine->update();
    }

    return 0;
}