#ifndef ALLOCATOR_SIMPLEST_INT_CONTAINER_H
#define ALLOCATOR_SIMPLEST_INT_CONTAINER_H

#include <memory>
#include "int_node.h"

class simplest_int_container{
public:
    simplest_int_container();
    void insert(int val);
    int* getPrev();
    bool hasPrev();
    int* GetLast();

protected:
    std::allocator<int> int_allocator_m_;
    int_node* first_int_node_;
    int_node* last_int_node_;
    int_node* current_int_node_;

    int* allocate_memory_procedure();
};


#endif //ALLOCATOR_SIMPLEST_INT_CONTAINER_H
