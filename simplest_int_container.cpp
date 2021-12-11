#include "simplest_int_container.h"

simplest_int_container::simplest_int_container() : first_int_node_(nullptr), last_int_node_(nullptr),
                                                    current_int_node_(nullptr){}

void simplest_int_container::insert(int val) {
    int* next_int_p = allocate_memory_procedure();
    next_int_p = &val;

    if (first_int_node_ == nullptr){
       first_int_node_ = new int_node(next_int_p);
       last_int_node_ = first_int_node_;
    } else {
        int_node* next_int_node = new int_node(next_int_p, last_int_node_);
        last_int_node_ = next_int_node;
    }

}

int* simplest_int_container::allocate_memory_procedure() {
    return int_allocator_m_.allocate(1);
}

int* simplest_int_container::GetLast() {
    return last_int_node_->IntItself();
}

bool simplest_int_container::hasPrev() {
    if (current_int_node_ == nullptr){
        if (last_int_node_ == first_int_node_ ){
            return false;
        } else return true;
    } else if (current_int_node_ == first_int_node_){
        return false;
    } else
        return true;
}

int* simplest_int_container::getPrev() {
    int* result;
    if (current_int_node_ == nullptr){
        result = last_int_node_->GetPrev()->IntItself();
    } else {
        result = current_int_node_->GetPrev()->IntItself();
    }
    current_int_node_ = current_int_node_->GetPrev();

    return result;
}