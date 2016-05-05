#include "CNode.hpp"

Data CNode::getData() {
    return this->elem;
}

CNode<Data>* CNode::getLeft() {
    return this->left;
}

CNode<Data>* CNode::getRight() {
    return this->right;

}
    
bool CNode::operator<(CNode<Data>* other) {
    if (this->elem < other->getData())
    {
        return 1;
    }

    return 0;
}