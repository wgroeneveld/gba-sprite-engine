//
// Created by SDM Technics on 30/12/2019.
//

#include "Enemy.h"

int Enemy::getLives() {
    return lives;
}

void Enemy::reduceLives(int value) {
    lives -= value;
}