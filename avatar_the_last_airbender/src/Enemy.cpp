#include "Enemy.h"

void Enemy::updateHealth(int health) {
    this->health = health;
    enemy->setBeginFrame(health-1);
}
