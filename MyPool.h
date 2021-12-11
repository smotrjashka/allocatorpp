//
// Created by Nastia on 01.12.2021.
//

#ifndef ALLOCATOR_MYPOOL_H
#define ALLOCATOR_MYPOOL_H
#include <cstdlib>

class MyPool
{
public:
    static MyPool& GetInstance();
    void* GetNext(std::size_t& n);
    void Free(void *ptr);

private:
    MyPool();
};


#endif //ALLOCATOR_MYPOOL_H
