#ifndef OOP_ALLCATIONBLOCK_H
#define OOP_ALLCATIONBLOCK_H

#include <cstdlib>
#include "../TreeAlloc/Tree.h"


class AllocationBlock {
public:
    AllocationBlock(int size,int cnt);

    void* Allocate();
    void Deallocate(void* pointer);

    virtual ~AllocationBlock();

private:
    unsigned char* usedBlocks;
    Tree<void*> freeBlocks;
};

#endif //OOP_ALLCATIONBLOCK_H
