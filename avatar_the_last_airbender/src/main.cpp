#include <libgba-sprite-engine/gba_engine.h>

#include "Scene_Start.h"
#include "Scene_Level1.h"

int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    Scene_Start* scene_start = new Scene_Start(engine);
    engine->setScene(scene_start);

//    Scene_Level1* sceneLevel1 = new Scene_Level1(engine);
  //  engine->setScene(sceneLevel1);

    while (true) {
        engine->update();
        engine->delay(1000);
    }

    return 0;
}