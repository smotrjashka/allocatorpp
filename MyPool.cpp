#include "MyPool.h"

MyPool::MyPool() {

}

MyPool& MyPool::GetInstance()
{
    static MyPool retval;
    return retval;
}

void* MyPool::GetNext(std::size_t& n, int amound) {
    return malloc(n*amound);
}

void MyPool::Free(void *ptr) {
    free(ptr);
}