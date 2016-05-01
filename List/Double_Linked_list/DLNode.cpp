#include "DLNode.hpp"

DLNode<Data>* DLNode::getNext() {
    return this->next;
}

DLNode<Data>* DLNode::getPre() {
    return this->pre;
}

bool DLNode::operator<(DLNode<Data>* other) {
    if (this->data < other->data)
    {
        return 1;
    }

    return 0;
}