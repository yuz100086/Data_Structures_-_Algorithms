#ifndef DLNODE_HPP
#define DLNODE_HPP

template <typename Data>
class DLNode
{
private:
    Data data;
    DLNode<Data>* next;
    DLNode<Data>* pre;
public:

    DLNode(Data data, 
           DLNode<Data>* ne, 
           DLNode<Data>* pre) : data(data), next(ne), pre(pre){}

    DLNode<Data>* getNext();

    DLNode<Data>* getPre();

    bool operator<(DLNode<Data>* other);
    
};
#endif