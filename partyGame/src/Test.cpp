//
// Created by michi on 18/07/2020.
//

#include "Test.h"
void Test::verhoogEersteGetal() {
    eersteGetal++;
}
void Test::verhoogTweedeGetal() {
    tweedeGetal++;
}
int Test::getEersteGetal() {
    return eersteGetal;
}
int Test::getTweedeGetal() {
    return tweedeGetal;
}

Test::Test() {
    eersteGetal = 5;
    tweedeGetal = 6;
}
