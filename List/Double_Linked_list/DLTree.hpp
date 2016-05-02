#ifndef DLTREE_HPP
#define  DLTREE_HPP

#include "DLNode.hpp"

class Node
{
public:
	DLNode<Data>* next;
	DLNode<Data>* pre;
	Node(DLNode<Data>* next = 0,
		 DLNode<Data>* pre = 0): next(next), pre(pre) {}
	
	
};

class DLTree
{
private:
	Node* head;
	Node* end;
	int nelem;
public:
    DLTree(Node* head = new Node(), 
    	   Node* end = new Node(), 
    	   n = 0) : head(head), end(end), nelem(n){}
    ~DLTree();
    
    void insert(Data data);

    void deleteFirst();

    void insertLast(Data data);

    void deleteLast();

    int size();

    bool find(Data data);

    Node* getHead();

    Node* getEnd();


};
#endif