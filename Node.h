#ifndef ALLOCATOR_NODE_H
#define ALLOCATOR_NODE_H

template<typename T>
class Node{
protected:
    T* val_itself_pointer_;
    Node<T>* prev_node_p_;

public:
    Node() = delete;

    Node(T *valItselfPointer) : val_itself_pointer_(valItselfPointer) {};

    Node(T *valItselfPointer, Node *prevNodeP) : val_itself_pointer_(valItselfPointer),
                                                    prev_node_p_(prevNodeP) {};

    T* tItself(){
        return val_itself_pointer_;
    };

    Node<T>* GetPrev(){
        return prev_node_p_;
    }

    void Prev(T* prevCand){
        if (prevCand == nullptr){
            RemovePrevNode();
        }
        if (prevCand != prev_node_p_){
            prev_node_p_ = prevCand;
        }
    }

    void RemovePrevNode(){
        prev_node_p_ = nullptr;
    }

};

#endif //ALLOCATOR_NODE_H
