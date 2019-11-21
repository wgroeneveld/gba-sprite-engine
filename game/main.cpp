//
// Created by Ben Luyck on 21/11/2019.
//
#include <cstdlib>
#include <ctime>
#include <iostream>

int level = -1;
const int aantalguns = 12;
bool leeg = true;
int shotgun[aantalguns];


void shootGun(int level){                   //aantal geweren bepalen dmv level en welke geweren kiezen
    int geweer = 0;
    for(int i=0; i<=(level+10)/10; i++){
        geweer=(rand()% aantalguns+1);
        shoot(geweer);
        shotgun[i] = geweer;
    }
}

bool geraakt(){
    if(posbullet == posspeler){
        return 1;
    }else{
        return 0;
    }
}

void levelend(){
    level = -1;
}

void buildscene(){};

int main(){
    if(level>=0) {
        if (leeg) {
            shootGun(level);       //level mee geven///welke guns bepalen in functie///aantal guns bepalen met level
        } else {
            if (geraakt()) {
                levelend();
            } else {
                level++;
            }
        }
    }else{
        buildscene();
    }
    return 0;
}



