#ifndef ALLOCATOR_INT_CONTAINER_PARAMETRIZED_WITH_ALLOCATOR_H
#define ALLOCATOR_INT_CONTAINER_PARAMETRIZED_WITH_ALLOCATOR_H

#include <memory>
#include "int_node.h"
#include "simplest_int_container.h"

template<typename Alloc = std::allocator<int> >
class int_container_parametrized_with_allocator : public simplest_int_container{
    using alloc_int = Alloc;
public:
    int_container_parametrized_with_allocator() {

    }

private:
    int* allocate_memory_procedure() {
        alloc_int_.allocate(1);
    }

    alloc_int alloc_int_;

};

#endif //ALLOCATOR_INT_CONTAINER_PARAMETRIZED_WITH_ALLOCATOR_H
