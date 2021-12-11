#ifndef ALLOCATOR_INT_NODE_H
#define ALLOCATOR_INT_NODE_H


class int_node {
private:
    int* int_itself_;
    int_node* pointer_to_prev_node_;


public:
    int_node() =delete;
    int_node(int* pInt);
    int_node(int* pInt, int_node* prev_node_pointer);

    int* IntItself();
    int_node* GetPrev();
    void SetPrev(int_node* p_int);
};


#endif //ALLOCATOR_INT_NODE_H
