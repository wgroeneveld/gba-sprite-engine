//
// Created by Wouter Groeneveld on 09/08/18.
//

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <cmath>

void Scene::addSprite(Sprite *sprite) {
    engine->dynamicallyAddSprite(sprite);
}


bool Scene::isObstacleInFront(Sprite *sprite, Background *background) {
    int realPositionX;
    int placeOnMap;
    int realPositionY = sprite->getY() + sprite->getHeight() + background->getScrollY();
    if((sprite->getX() + sprite->getWidth() + background->getScrollX())/8 > 31){
        realPositionX = sprite->getX() + sprite->getWidth() + background->getScrollX();
        placeOnMap = (realPositionX/8)-32 + ((realPositionY/8)-1)*32 + 1024;
    }
    else{
        realPositionX = sprite->getX() + sprite->getWidth() + background->getScrollX();
        placeOnMap = (realPositionX/8) + ((realPositionY/8)-1)*32;
    }
    bool isInFront;
    if(sprite->getHeight() == 64){
        for (int i = 0; i < ((sprite->getHeight())/8)-3 ; ++i) {
            if(background->getMapData()[placeOnMap-(i*32)] == 0x0000){
                isInFront = FALSE;
            }
            else{
                isInFront = TRUE;
                break;
            }
        }
    }
    else{
        for (int i = 0; i <= ((sprite->getHeight())/8)-1 ; ++i) {
            if(background->getMapData()[placeOnMap-(i*32)] == 0x0000){
                isInFront = FALSE;
            }
            else{
                isInFront = TRUE;
                break;
            }
        }
    }
    return isInFront;
}

int Scene::isObstacleInFrontInt(Sprite *sprite, Background *background) {
    int realPositionX = sprite->getX() + background->getScrollX();
    int realPositionY = sprite->getY() + sprite->getHeight() + background->getScrollY();
    int placeOnMap = (realPositionX/8) + ((realPositionY/8)-1)*32;
    return placeOnMap;
}

unsigned short int Scene::isObstacleInFrontIntVector(Sprite *sprite, Background *background) {
    int realPositionX = sprite->getX() + background->getScrollX();
    int realPositionY = sprite->getY() + sprite->getHeight() + background->getScrollY();
    int placeOnMap = (realPositionX/8) + ((realPositionY/8)-1)*32;
    return background->getMapData()[placeOnMap-32];
}

bool Scene::isObstacleBehind(Sprite* sprite, Background* background) {
    int realPositionX;
    int placeOnMap;
    int realPositionY = sprite->getY() + sprite->getHeight() + background->getScrollY();
    if(sprite->getX() + background->getScrollX() > 255){
        realPositionX = sprite->getX() + background->getScrollX();
        placeOnMap = (realPositionX/8)-32 + ((realPositionY/8)-1)*32 + 1024;
    }
    else{
        realPositionX = sprite->getX() + background->getScrollX();
        placeOnMap = (realPositionX/8) + ((realPositionY/8)-1)*32;
    }
    bool isBehind;
    if(sprite->getHeight() == 64){
        for (int i = 0; i < ((sprite->getHeight())/8)-3 ; ++i) {
            if(background->getMapData()[placeOnMap-(i*32)] == 0x0000){
                isBehind = FALSE;
            }
            else{
                isBehind = TRUE;
                break;
            }
        }
    }
    else{
        for (int i = 0; i <= ((sprite->getHeight())/8)-1 ; ++i) {
            if(background->getMapData()[placeOnMap-(i*32)] == 0x0000){
                isBehind = FALSE;
            }
            else{
                isBehind = TRUE;
                break;
            }
        }
    }
    return isBehind;
}

bool Scene::isObstacleAbove(Sprite *sprite, Background *background) {

    int realPositionY = sprite->getY() + background->getScrollY();
    int realPositionX = sprite->getX() + sprite->getWidth() + background->getScrollX();
    int placeOnMap = (realPositionX/8) + ((realPositionY/8)-1)*32;
    int placeOnMap2 = (realPositionX/8)-32 + ((realPositionY/8)-1)*32 + 1024;
    if((sprite->getX() + sprite->getWidth() + background->getScrollX())/8 > 35){
        return !(background->getMapData()[placeOnMap2 + 127] == 0x0000 &&
                 background->getMapData()[placeOnMap2 + 127 - sprite->getWidth() / 8 + 1] == 0x0000
                 && background->getMapData()[placeOnMap2 + 127 - sprite->getWidth() / 8 + 3] == 0x0000);
    }
    else if ((sprite->getX() + sprite->getWidth() + background->getScrollX())/8 > 34){
        return !(background->getMapData()[placeOnMap2 + 127] == 0x0000 &&
                 background->getMapData()[placeOnMap + 127 - sprite->getWidth() / 8 + 1] == 0x0000
                 && background->getMapData()[placeOnMap2 + 127 - sprite->getWidth() / 8 + 3] == 0x0000);
    }
    else if ((sprite->getX() + sprite->getWidth() + background->getScrollX())/8 > 33){
        return !(background->getMapData()[placeOnMap2 + 127] == 0x0000 &&
                 background->getMapData()[placeOnMap + 127 - sprite->getWidth() / 8 + 2] == 0x0000
                 && background->getMapData()[placeOnMap2 + 127 - sprite->getWidth() / 8 + 3] == 0x0000);
    }
    else if ((sprite->getX() + sprite->getWidth() + background->getScrollX())/8 > 32){
        return !(background->getMapData()[placeOnMap2 + 127] == 0x0000 &&
                 background->getMapData()[placeOnMap + 127 - sprite->getWidth() / 8 + 2] == 0x0000
                 && background->getMapData()[placeOnMap + 127 - sprite->getWidth() / 8 + 3] == 0x0000);
    }
    else{
        return !(background->getMapData()[placeOnMap + 127] == 0x0000 &&
                 background->getMapData()[placeOnMap + 127 - sprite->getWidth() / 8 + 2] == 0x0000
                 && background->getMapData()[placeOnMap + 127 - sprite->getWidth() / 8 + 3] == 0x0000);
    }
}

bool Scene::isObstacleBelow(Sprite *sprite, Background *background) {
    int realPositionY = sprite->getY() + sprite->getHeight() + background->getScrollY();
    int realPositionX = sprite->getX() + sprite->getWidth() + background->getScrollX();
    int placeOnMap = (realPositionX/8) + ((realPositionY/8)-1)*32;
    int placeOnMap2 = (realPositionX/8)-32 + ((realPositionY/8)-1)*32 + 1024;
    if((sprite->getX() + sprite->getWidth() + background->getScrollX())/8 > 35){
        return !(background->getMapData()[placeOnMap2 + 31] == 0x0000 &&
                 background->getMapData()[placeOnMap2 + 31 - sprite->getWidth() / 8 + 1] == 0x0000
                 && background->getMapData()[placeOnMap2 + 31 - sprite->getWidth() / 8 + 3] == 0x0000);
    }
    else if ((sprite->getX() + sprite->getWidth() + background->getScrollX())/8 > 34){
        return !(background->getMapData()[placeOnMap2 + 31] == 0x0000 &&
                 background->getMapData()[placeOnMap + 31 - sprite->getWidth() / 8 + 1] == 0x0000
                 && background->getMapData()[placeOnMap2 + 31 - sprite->getWidth() / 8 + 3] == 0x0000);
    }
    else if ((sprite->getX() + sprite->getWidth() + background->getScrollX())/8 > 33){
        return !(background->getMapData()[placeOnMap2 + 31] == 0x0000 &&
                 background->getMapData()[placeOnMap + 31 - sprite->getWidth() / 8 + 2] == 0x0000
                 && background->getMapData()[placeOnMap2 + 31 - sprite->getWidth() / 8 + 3] == 0x0000);
    }
    else if ((sprite->getX() + sprite->getWidth() + background->getScrollX())/8 > 32){
        return !(background->getMapData()[placeOnMap2 + 31] == 0x0000 &&
                 background->getMapData()[placeOnMap + 31 - sprite->getWidth() / 8 + 2] == 0x0000
                 && background->getMapData()[placeOnMap + 31 - sprite->getWidth() / 8 + 3] == 0x0000);
    }
    else{
        return !(background->getMapData()[placeOnMap + 31] == 0x0000 &&
                 background->getMapData()[placeOnMap + 31 - sprite->getWidth() / 8 + 2] == 0x0000
                 && background->getMapData()[placeOnMap + 31 - sprite->getWidth() / 8 + 3] == 0x0000);
    }
}
