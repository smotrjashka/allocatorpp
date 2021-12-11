#ifndef ALLOCATOR_SIMP_PARAM_CONTAINER_H
#define ALLOCATOR_SIMP_PARAM_CONTAINER_H

#include <memory>
#include "Node.h"

template<typename T, typename Alloc = std::allocator<T>>
struct simp_param_container{
    using alloc_t = Alloc;

public:
    simp_param_container() : first_node_(nullptr), last_node_(nullptr), current_node_(nullptr) {};
    void insert(T val){
        T* next_p = allocate_memory_for_one();
        next_p = &val;

        if (first_node_ == nullptr){
            first_node_ = new Node<T>(next_p);
            last_node_ = first_node_;
        } else {
            Node<T>* next_node = new Node<T>(next_p, last_node_);
            last_node_ = next_node;
        }

    };

    T* GetLast(){
        return last_node_->tItself();
    };

    bool hasPrev(){
        if (current_node_ == nullptr){
            if (last_node_ == first_node_ ){
                return false;
            } else return true;
        } else if (current_node_ == first_node_){
            return false;
        } else
            return true;
    };

    T* getPrev(){
        T* result;
        if (current_node_ == nullptr){
            result = last_node_->GetPrev()->tItself();
        } else {
            result = current_node_->GetPrev()->tItself();
        }
        current_node_ = current_node_->GetPrev();

        return result;
    };


protected:
    alloc_t allocator_m_;
    Node<T>* first_node_;
    Node<T>* last_node_;
    Node<T>* current_node_;

    T* allocate_memory_for_one(){
        return allocator_m_.allocate(1);
    };



};


#endif //ALLOCATOR_SIMP_PARAM_CONTAINER_H
