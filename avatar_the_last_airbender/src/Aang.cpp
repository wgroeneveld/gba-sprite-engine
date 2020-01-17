#include "Aang.h"

#include <libgba-sprite-engine/gba_engine.h>

#include <cmath>

void Aang::tick(u16 keys) {
    if (keys & KEY_LEFT) {
        if(!walkingLeft) walkingLeft = true;
    }
    else {
        walkingLeft = false;
    }
    if (keys & KEY_RIGHT) {
        if(!walkingRight) walkingRight = true;
    }
    else {
        walkingRight = false;
    }
    if (keys & KEY_A) {
        if (!jumping) {
            jumping = true;
            aangUpSprite->setBeginFrame(0);
        }
    }
    if (keys & KEY_B) {
        if (!attacking && !jumping) {
            attacking = true;
            aangUpSprite->setBeginFrame(3);
        }
    }

    if (walkingLeft && !attacking) {
        aangDownSprite->flipHorizontally(true);
        aangUpSprite->flipHorizontally(true);
        launchLeft = true;
        if (!aangDownSprite->isAnimating()) {
            aangDownSprite->makeAnimated(1, 2, 10);
        }
        if (aangDownSprite->getX() > 0) {
            moveOthers = false;
            move();
        } else moveOthers = true;
    }


    if (walkingRight && !attacking) {
        aangDownSprite->flipHorizontally(false);
        aangUpSprite->flipHorizontally(false);
        launchLeft = false;
        if (!aangDownSprite->isAnimating()) {
            aangDownSprite->makeAnimated(1, 2, 10);
        }
        if (aangDownSprite->getX() < 190) {

            moveOthers = false;
            move();
        } else moveOthers = true;
    }


    if (((!walkingLeft && !walkingRight) || jumping || attacking) && aangDownSprite->isAnimating() && (aangDownSprite->getCurrentFrame() == 1 || aangDownSprite->getCurrentFrame() == 2)) {
        aangDownSprite->stopAnimating();
        aangDownSprite->animateToFrame(0);
    }


    if (jumping) {
        if (!aangDownSprite->isAnimating()) {
            aangDownSprite->makeAnimated(3, 2, 15);
            aangUpSprite->makeAnimated(2, 15);
            aangUpSprite->moveTo(aangDownSprite->getX(), yPosition - 32);
        }

        yVelocity = -(pow(((0.17 * timer) - 3), 2)) + ((2 * timer) - 3) + 12;
        int yPosition = 83 - yVelocity;
        aangDownSprite->moveTo(aangDownSprite->getX(), yPosition);
        aangUpSprite->moveTo(aangUpSprite->getX(), yPosition - 32);

        if (aangDownSprite->getY() != yPositionDefault) {
            timer++;
        } else {
            jumping = false;
            timer = 1;
            aangDownSprite->stopAnimating();
            aangDownSprite->animateToFrame(0);
            aangUpSprite->stopAnimating();
            aangUpSprite->moveTo(GBA_SCREEN_WIDTH + 10, GBA_SCREEN_HEIGHT + 10);
        }

    }

    if (attacking && !aangDownSprite->isAnimating()) aangDownSprite->makeAnimated(5, 4, 20);
    if (attacking && aangDownSprite->getCurrentFrame() == 6) {
        aangUpSprite->animateToFrame(2);
    }
    if (attacking && aangUpSprite->getCurrentFrame() == 2) {
        aangUpSprite->makeAnimated(2, 20);
        aangUpSprite->moveTo(aangDownSprite->getX(), aangDownSprite->getY() - 32);
    }
    if (attacking && aangDownSprite->getCurrentFrame() > 7) {
        launchAirball = true;
        attacking = false;
        aangDownSprite->animateToFrame(7);
        aangDownSprite->stopAnimating();
        aangDownSprite->animateToFrame(0);
        aangUpSprite->stopAnimating();
        aangUpSprite->moveTo(GBA_SCREEN_WIDTH + 10, GBA_SCREEN_HEIGHT + 10);
    }
    else {
        launchAirball = false;
    }
}

void Aang::move() {
    if (walkingLeft && !attacking) {
        aangDownSprite->moveTo(aangDownSprite->getX() - xVelocity, aangDownSprite->getY());
        if(jumping) {
            aangUpSprite->moveTo(aangDownSprite->getX() - xVelocity, aangDownSprite->getY()-32);
        }
    }

    if (walkingRight && !attacking) {
        aangDownSprite->moveTo(aangDownSprite->getX() + xVelocity, aangDownSprite->getY());
        if(jumping) {
            aangUpSprite->moveTo(aangDownSprite->getX() + xVelocity, aangDownSprite->getY()-32);
        }
    }
}

void Aang::setHealth(int health) {
    this->health = health;
    switch (health){
        case 3:
            aangHealthbarSprite->animateToFrame(0);
            break;
        case 2:
            aangHealthbarSprite->animateToFrame(1);
            break;
        case 1:
            aangHealthbarSprite->animateToFrame(2);
            break;
        default:
            aangHealthbarSprite->animateToFrame(0);
            break;
    }
}
