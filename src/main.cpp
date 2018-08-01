#include <engine/Scene.h>
#include <engine/gba_engine.h>
#include <engine/background/text.h>
#include <engine/background/text_stream.h>
#include <engine/palette_manager.h>
#include <engine/allocator.h>

#include "kul.h"
#include "flying_stuff_scene.h"

int main() {
    GBAEngine engine;
    TextStream::instance() << "abc123 sup";

    // shared palette extracted from grit
    // ./../grit piskel.png piskel2.png kul.png -ftc -pS -gB8 -O shared.c
    // assumes 8bpp sprites
    ForegroundPaletteManager fgPalette(sharedPal, sizeof(sharedPal));
    BackgroundPaletteManager bgPalette(bg_palette, sizeof(bg_palette));
    fgPalette.persist();
    bgPalette.persist();

    FlyingStuffScene flyingStuffScene;
    engine.setScene(flyingStuffScene);


    while (true) {
        engine.render();
        //engine.delay(1000);
    }

    return 0;
}