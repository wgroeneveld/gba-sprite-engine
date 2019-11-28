//
// Created by woute on 21/11/2019.
//

#ifndef LABO9_GBA_H
#define LABO9_GBA_H

#include <bits/unique_ptr.h>
#include "MemoryManager.h"

using namespace std;

class GBA{
private:
    unique_ptr<MemoryManager> manager;

public:
    void vblank(){
        cout << "vblank"<<endl;
    };
    void run(){
        cout << "loooopeeeen, run forest run!"<<endl;};
    void init(){
        manager = unique_ptr<MemoryManager>(new MemoryManager(99));
    };
};

#endif //LABO9_GBA_H
