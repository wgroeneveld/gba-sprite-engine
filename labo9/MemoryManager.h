//
// Created by woute on 21/11/2019.
//

#ifndef LABO9_MEMORYMANAGER_H
#define LABO9_MEMORYMANAGER_H

#include "BaseBGLayer.h"

using namespace std;

class MemoryManager{
    unique_ptr<int> memory;

public:
    MemoryManager(int i) {
    };
    void safe(BaseBGLayer bglayer);
};

#endif //LABO9_MEMORYMANAGER_H
