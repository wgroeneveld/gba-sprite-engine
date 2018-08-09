//
// Created by Wouter Groeneveld on 09/08/18.
//

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>

void Scene::addSprite(Sprite *sprite) {
    engine->dynamicallyAddSprite(sprite);
}
