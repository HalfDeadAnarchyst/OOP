//
// Created by Никита on 05.12.16.
//

#include "AllcationBlock.h"

AllocationBlock::AllocationBlock(int size, int cnt) {
    usedBlocks = (unsigned char*)malloc(size * cnt);

    for(int i = 0; i < cnt; ++i) {
        void* ptr = (void*)malloc(sizeof(void*));
        ptr = usedBlocks + i * size;
        freeBlocks.Insert(ptr);
    }
}

void* AllocationBlock::Allocate() {
//    std::lock_guard<std::recursive_mutex> lock(allocationMutex);
    if(!freeBlocks.Empty()) {
        return freeBlocks.Pull(0);
    }
    else {
        throw std::bad_alloc();
    }
}

void AllocationBlock::Deallocate(void* pointer) {
//    std::lock_guard<std::recursive_mutex> lock(allocationMutex);
    freeBlocks.Insert(pointer);
}

AllocationBlock::~AllocationBlock() {
    if(!freeBlocks.Empty()) {
        while(!freeBlocks.Empty()) {
            freeBlocks.Pull(0);
        }
    }
    freeBlocks.Delete();

    free(usedBlocks);
}