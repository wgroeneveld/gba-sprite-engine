//
// Created by michi on 14/04/2020.
//

#include "Speler.h"

int Speler::getScore() {
    return score;
}

void Speler::setScore(int nieuweScore) {
    score = nieuweScore;
}

Speler::Speler() {
    score = 10;
}
