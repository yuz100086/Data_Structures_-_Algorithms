#ifndef CNODE_HPP
#define CNODE_HPP

template <typename Data>
class CNode
{
private:
    Data elem;
    CNode<Data>* left;
    CNode<Data>* right;
public:
    CNode(Data e,
          CNode<Data>* left = 0, 
          CNode<Data>* right = 0):{elem(e), left(left), right(right)}

    Data getData();

    CNode<Data>* getLeft();

    CNode<Data>* getRight();
    
    bool operator<(CNode<Data>* other);
    
};
#endif