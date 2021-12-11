#ifndef ALLOCATOR_MYPOOL_H
#define ALLOCATOR_MYPOOL_H
#include <cstdlib>

class MyPool
{
public:
    static MyPool& GetInstance();
    void* GetNext(std::size_t& n, int amound);
    void Free(void *ptr);

private:
    MyPool();
};


#endif //ALLOCATOR_MYPOOL_H
