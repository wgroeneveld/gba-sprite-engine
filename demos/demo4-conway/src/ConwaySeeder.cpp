//
// Created by Wouter Groeneveld on 30/11/18.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include "ConwaySeeder.h"
#include "bg.h"
#include "NaiveConwayScene.h"
#include "ActiveTrackingConwayScene.h"

ConwaySeeder::ConwaySeeder(const std::shared_ptr<GBAEngine> &engine) : Scene(engine), percentage(30), delta(0), impl(1) {}

std::vector<Background *> ConwaySeeder::backgrounds() {
    return {};
}

std::vector<Sprite *> ConwaySeeder::sprites() {
    return {
        conwaySprite.get()
    };
}

void ConwaySeeder::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(conway_palette, sizeof(conway_palette)));

    SpriteBuilder<Sprite> builder;
    conwaySprite = builder
            .withData(conway_data, sizeof(conway_data))
            .withSize(SIZE_32_8)
            .withLocation(GBA_SCREEN_WIDTH - 40, 8)
            .buildPtr();

    TextStream::instance().setText(std::string("Conways Game of Life"), 1, 1);
    TextStream::instance().setText(std::string("Up/Down to adjust seed"), 10, 1);
    TextStream::instance().setText(std::string("A/B to adjust impl"), 11, 1);
    TextStream::instance().setText(std::string("Start to render"), 12, 1);
}

void ConwaySeeder::tick(u16 keys) {
    TextStream::instance().setText(std::string("Seed percentage: ") + std::to_string(percentage), 5, 1);
    TextStream::instance().setText(std::string("Seed impl: ") + (impl == 1 ? std::string("naive") : std::string("fast")), 6, 1);

    if(keys & KEY_A) {
        impl = 1;
    } else if(keys & KEY_B) {
        impl = 2;
    }

    if(keys & KEY_START) {
        if(impl == 1) {
            engine.get()->setScene(new NaiveConwayScene(engine, percentage));
        } else {
            engine.get()->setScene(new ActiveTrackingConwayScene(engine, percentage));
        }
    } else if(keys & KEY_UP && percentage < 90) {
        delta = 1;
    } else if(keys & KEY_DOWN && percentage > 5) {
        delta = -1;
    } else {
        if(delta != 0) {
            percentage += 5 * delta;
            delta = 0;
        }
    }
}