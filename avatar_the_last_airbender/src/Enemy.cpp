#include "Enemy.h"

void Enemy::updateHealth(int health) {
    this->health = health;
    switch (health){
        case 3:
            healthbar->animateToFrame(0);
            break;
        case 2:
            healthbar->animateToFrame(1);
            break;
        case 1:
            healthbar->animateToFrame(2);
            break;
        default:
            healthbar->animateToFrame(0);
            break;
    }
}

void Enemy::tick() {
    if(directionIsLeft){
        enemy->flipHorizontally(true);
        enemy->moveTo(enemy->getX()-1,enemy->getY());
        healthbar->moveTo(healthbar->getX()-1,healthbar->getY());
    }else{
        enemy->moveTo(enemy->getX()+1,enemy->getY());
        healthbar->moveTo(healthbar->getX()+1,healthbar->getY());
    }
}


