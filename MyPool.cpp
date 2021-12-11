#include "MyPool.h"

MyPool::MyPool() {

}

MyPool& MyPool::GetInstance()
{
    static MyPool retval;
    return retval;
}

void* MyPool::GetNext(std::size_t& n) {
    return malloc(n);
}

void MyPool::Free(void *ptr) {
    free(ptr);
}