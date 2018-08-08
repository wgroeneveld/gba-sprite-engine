//
// Created by Wouter Groeneveld on 27/07/18.
//

#include <stdexcept>
#include <libgba-sprite-engine/allocator.h>

u32 voidPtrToU32(void* ptr) {
    return static_cast<u32>(reinterpret_cast<intptr_t>(ptr));
}

u32 Allocator::currentSpriteIndex;
std::vector<AllocatedData> Allocator::allocatedSprites;

AllocatedData& Allocator::allocateObjectTiles(u32 size) {
    AllocatedData s(currentSpriteIndex, size, MEM_OBJ_VRAM_BASE);
    currentSpriteIndex += size;

    allocatedSprites.push_back(s);
    return allocatedSprites.at(allocatedSprites.size() - 1);
}

void Allocator::free() {
    allocatedSprites.clear();

    currentSpriteIndex = MEM_OBJ_VRAM_BASE;
}