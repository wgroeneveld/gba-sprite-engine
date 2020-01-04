//
// Created by Wouter Groeneveld on 09/08/18.
//

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <cmath>

void Scene::addSprite(Sprite *sprite) {
    engine->dynamicallyAddSprite(sprite);
}

//Algemeen idee, moeten if's bij om te checken of de eerste of laatste blok getest wordt van die rij
bool Scene::isObstacleInFront(Sprite *sprite, Background *background) {
    int realPositionX = sprite->getX() + sprite->getWidth() + background->getScrollX();
    int realPositionY = sprite->getY() + sprite->getHeight() + background->getScrollY();
    int placeOnMap = (realPositionX/8) + ((realPositionY/8)-1)*32;
    if(background->getMapData()[placeOnMap] == 0x0000){
        return FALSE;
    }
    else{
        return TRUE;
    }
    return TRUE;
}

bool Scene::isObstacleBehind(Sprite* sprite, Background* background) {
    int realPositionX = sprite->getX() + background->getScrollX();
    int realPositionY = sprite->getY() + sprite->getHeight() + background->getScrollY();
    int placeOnMap = (realPositionX/8) + ((realPositionY/8)-1)*32;
    if(background->getMapData()[placeOnMap] == 0x0000){
        return FALSE;
    }
    else{
        return TRUE;
    }
    return TRUE;
}

bool Scene::isObstacleAbove(Sprite *sprite, Background *background) {
    int realPositionX = sprite->getX() + background->getScrollX();
    int realPositionY = sprite->getY() + sprite->getHeight() + background->getScrollY();
    int placeOnMap = (realPositionX/8) + ((realPositionY/8)-1)*32;
    /*if(maparray[placeOnMap-32] == 0x0000){
        return FALSE;
    }
    else{
        return TRUE;
    }*/
    return FALSE;
}

bool Scene::isObstacleBelow(Sprite sprite, Background background) {
    int realPositionX = sprite.getX() + background.getScrollX();
    int realPositionY = sprite.getY() + background.getScrollY();
    int placeOnMap = (realPositionX/8) + ((realPositionY/8)-1)*32;
    /*if(maparray[placeOnMap+32] == 0x0000){
        return FALSE;
    }
    else{
        return TRUE;
    }*/
    return TRUE;
}
