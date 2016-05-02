#ifndef NODE_HPP
#define NODE_HPP

#include "DLNode.hpp"
template <typename Data>
class Node
{
public:
    DLNode<Data>* next;
    DLNode<Data>* pre;
    Node(DLNode<Data>* next = 0,
         DLNode<Data>* pre = 0): next(next), pre(pre) {}
    
    
};
#endif