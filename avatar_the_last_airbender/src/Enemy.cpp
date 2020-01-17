#include "Enemy.h"

void Enemy::updateHealth(int newHealth) {
    this->health = newHealth;
    switch (newHealth){
        case 3:
            enemyHealthbarSprite->animateToFrame(0);
            break;
        case 2:
            enemyHealthbarSprite->animateToFrame(1);
            break;
        case 1:
            enemyHealthbarSprite->animateToFrame(2);
            break;
        default:
            enemyHealthbarSprite->animateToFrame(0);
            break;
    }
}


void Enemy::tick() {
    timer++;
    if(timer%10 != 0) return;
    if(walkingLeft){
        enemySprite->flipHorizontally(true);
        enemySprite->moveTo(enemySprite->getX() - 1, enemySprite->getY());
        enemyHealthbarSprite->moveTo(enemyHealthbarSprite->getX() - 1, enemyHealthbarSprite->getY());
    }
    else {
        enemySprite->flipHorizontally(false);
        enemySprite->moveTo(enemySprite->getX() + 1, enemySprite->getY());
        enemyHealthbarSprite->moveTo(enemyHealthbarSprite->getX() + 1, enemyHealthbarSprite->getY());
    }
    if(!enemySprite->isAnimating()) {
        enemySprite->makeAnimated(2, 15);
    }
}


