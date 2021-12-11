#include "int_node.h"

int_node::int_node(int *pInt) : int_itself_(pInt), pointer_to_prev_node_(nullptr){
}

int_node::int_node(int *pInt, int_node *prev_node_pointer) : int_itself_(pInt), pointer_to_prev_node_(prev_node_pointer){}

int *int_node::IntItself() {
    return int_itself_;
}

int_node* int_node::GetPrev() {
    return pointer_to_prev_node_;
}

void int_node::SetPrev(int_node *p) {
    pointer_to_prev_node_ = p;
}