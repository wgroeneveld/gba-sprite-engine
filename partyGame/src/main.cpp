//
// Created by michi on 21/03/2020.
//

#include <libgba-sprite-engine/gba_engine.h>

#include "../screens/MainMenuScreen.h"
#include "../screens/testScreen2.h"

int main() {

    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    auto mainMenu = new MainMenuScreen(engine);
    //auto mainMenu = new testScreen2(engine);
    engine->setScene(mainMenu);

    while(true) {
        engine->update();
        engine->delay(1000);
    }

}
