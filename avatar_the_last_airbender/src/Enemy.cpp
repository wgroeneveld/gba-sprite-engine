#include "Enemy.h"

void Enemy::updateHealth(int health) {
    this->health = health;
    switch (health){
        case 3:
            healthbarSprite->animateToFrame(0);
            break;
        case 2:
            healthbarSprite->animateToFrame(1);
            break;
        case 1:
            healthbarSprite->animateToFrame(2);
            break;
        default:
            healthbarSprite->animateToFrame(0);
            break;
    }
}

//COMMENTAAR DAT WEG MAG: Ik heb hier alles volledig veranderd
//Dus je kunt twee types enemy hebben: statisch of dynamisch
//Als de enemy statisch is blijft die gewoon op een bepaalde plaats en  flip to om de zoveel seconden zodat die toch beetje geanimeerd is
//Als de enemy dynamisch is dan loopt die van zijn xBeginPosition naar zijn xEndPosition
int counter = 0;
void Enemy::tick() {
    counter++;
    if(staticPosition) {
        if(counter%100 != 0) return;
        if(direction == LEFT) {
            direction = RIGHT;
            enemySprite->flipHorizontally(false);
        }
        else if (direction == RIGHT) {
            direction = LEFT;
            enemySprite->flipHorizontally(true);
        }
    }
    else {
        if(counter%10 != 0) return;
        if(enemySprite->getX() == beginXPosition) direction = RIGHT;
        else if(enemySprite->getX() == endXPosition) direction = LEFT;

        if(direction == LEFT){
            enemySprite->flipHorizontally(true);
            enemySprite->moveTo(enemySprite->getX() - 1, enemySprite->getY());
            healthbarSprite->moveTo(healthbarSprite->getX() - 1, healthbarSprite->getY());
        }
        else if(direction == RIGHT){
            enemySprite->flipHorizontally(false);
            enemySprite->moveTo(enemySprite->getX() + 1, enemySprite->getY());
            healthbarSprite->moveTo(healthbarSprite->getX() + 1, healthbarSprite->getY());
        }

        if(!enemySprite->isAnimating()) {
            enemySprite->makeAnimated(2, 25);
        }
    }
}


