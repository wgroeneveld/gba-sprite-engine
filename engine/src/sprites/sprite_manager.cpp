//
// Created by Wouter Groeneveld on 26/07/18.
//

#include <libgba-sprite-engine/sprites/sprite_manager.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>

#include <libgba-sprite-engine/gba/tonc_core.h>
#include <libgba-sprite-engine/allocator.h>

#define MAX_SPRITE_SIZE 128
#define MAX_AFFINE_SIZE 31

void SpriteManager::set(std::vector<Sprite *> sprites) {
    initialized = false;

    this->sprites.clear();
    this->sprites.insert(this->sprites.end(), sprites.begin(), sprites.end());
}

void SpriteManager::add(const Sprite &sprite) {
    if(sprites.size() == MAX_SPRITE_SIZE) {
        throw std::runtime_error("maximum sprite limit reached");
    }

    const Sprite* sPtr = &sprite;
    sprites.push_back(const_cast<Sprite*>(sPtr));
}

void SpriteManager::render() {
    if(!initialized) {
        throw std::runtime_error("can't render before initialization");
    }

    copyOverSpriteOAMToVRAM();
}

void SpriteManager::persist() {
    copyOverImageDataToVRAM();
    initialized = true;
}

void SpriteManager::copyOverSpriteOAMToVRAM() {
    int i = 0;
    int affineIndex = 0;

    for(auto sprite : this->sprites) {
        if(affineIndex > MAX_AFFINE_SIZE) {
            throw std::runtime_error("max amount of sprites with affine matriches reached");
        }
        sprite->update();

        auto oam = sprite->oam.get();
        oam_mem[i] = *oam;

        auto affine = dynamic_cast<AffineSprite*>(sprite);
        if(affine) {
            // WHY warning: can't do this: obj_aff_mem[affineIndex] = *affineShadow;
            // because that would override OAM also! only want to set non-overlapping affine attribs

            affine->setTransformationMatrix(&obj_aff_mem[affineIndex]);
            affine->setAffineIndex(affineIndex);
            affineIndex++;
        }

        i++;
    }
    for(int j = i; j < MAX_SPRITE_SIZE; j++) {
        oam_mem[j].attr0 = ATTR0_HIDE;
    }
}

void SpriteManager::copyOverImageDataToVRAM() {
    for(auto sprite : this->sprites) {
        const auto allocated = Allocator::allocateObjectTiles(sprite->imageSize);
        dma3_cpy(allocated.pointer(), sprite->data, allocated.size);

        sprite->buildOam(allocated.getTileLocation());
    }
}
