//
// Created by Wouter Groeneveld on 29/11/18.
//

#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "SplashScreen.h"
#include "arkanoid_game_scene.h"

#include "splashimage.h"
#include "omnom.h"

SplashScreen::SplashScreen(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Sprite *> SplashScreen::sprites() {
    return {};
}

std::vector<Background *> SplashScreen::backgrounds() {
    return {
        bg.get()
    };
}

void SplashScreen::tick(u16 keys) {
    if(keys & KEY_ANY) {
        engine->setScene(new ArkanoidGameScene(engine));
    }
}

void SplashScreen::load() {
    // we need to disable the text background because the splash screen is too big and fills up al char blocks (including map)
    // remember, we have background char blocks 0, 1, 2, 3, each consisting of 8 screen blocks, from 0x6000000 to 0x6000f800 (last screen block, 31)
    engine.get()->disableText();
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(splashimagePal, sizeof(splashimagePal)));

    // use background number 0, as the text bg is disabled, to start dumping into VRAM from 0x6000000
    // data exported from grit using: "grit splashimage.png -gt -gB8 -mRtpf -mLs -ftc", see https://www.coranac.com/man/grit/html/grit.htm or https://github.com/devkitPro/grit/blob/master/grit-readme.txt
    // do NOT use "-Mw" or "-Mh", regular map needed, no metamap.

    // the photograph was first edited in GIMP to contain max. 255 colors using image -> mode -> indexed colors.
    bg = std::unique_ptr<Background>(new Background(0, splashimageTiles, sizeof(splashimageTiles), splashimageMap, sizeof(splashimageMap)));

    // the last char block (3) starts at screen block 24, is still available to dump the tilemap in.
    bg.get()->useMapScreenBlock(24);

    engine.get()->enqueueSound(omnom, omnom_bytes, 44200);
}
