//
// Created by michi on 21/03/2020.
//

#include <libgba-sprite-engine/gba_engine.h>

#include "MainMenu.h"

int main() {

    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    auto mainMenu = new MainMenu(engine);
    engine->setScene(mainMenu);

    while(true) {
        engine->update();
        engine->delay(1000);
    }

}
