#ifndef DLTREE_HPP
#define  DLTREE_HPP

#include <iostream>
#include "DLNode.hpp"
#include "Node.hpp"
template <typename Data>
class DLTree
{
private:
	Node<Data>* head;
	Node<Data>* end;
	int nelem;
public:
    DLTree(Node<Data>* head = new Node<Data>(), 
    	   Node<Data>* end = new Node<Data>(), 
    	   int n = 0) : head(head), end(end), nelem(n){}

    ~DLTree() {
        DLNode<Data>* temp = getHead()->next;
        DLNode<Data>* tmp = 0;
        while(temp != 0) {
            tmp = temp->next;
            delete temp;
            temp = tmp;
        }

        delete this->head;

        delete this->end;
    }

    void insert(Data data) {
        Node<Data>* hed = getHead();
        DLNode<Data>* temp = hed->next;

        DLNode<Data>* node = new DLNode<Data>(data, 0, 0);
        
        this->nelem++;

        hed->next = node;

        node->next = temp;

        if (temp != 0)
        {
            temp->pre = node;
            return;
        }

        hed = getEnd();

        hed->pre = node;

    }

    void deleteFirst() {
        Node<Data>* hed = getHead();

        if (hed->next == 0)
        {
            return;
        }

        DLNode<Data>* temp = hed->next->next;

        delete hed->next;

        this->nelem--;

        hed->next = temp;
        
        if (temp != 0)
        {
            temp->pre = 0;
        }
    }

    void insertLast(Data data) {
        Node<Data>* hed = getEnd();
        DLNode<Data>* temp = hed->pre;

        DLNode<Data>* node = new DLNode<Data>(data, 0, 0);
        
        this->nelem++;

        hed->pre = node;

        node->pre = temp;

        if (temp != 0)
        {
            temp->next = node;
            return;
        }

        hed = getHead();

        hed->next = node;
    }

    void deleteLast() {
        Node<Data>* hed = getEnd();

        if (hed->pre == 0)
        {
            return;
        }

        DLNode<Data>* temp = hed->pre->pre;

        delete hed->pre;

        this->nelem--;

        hed->pre = temp;
        
        if (temp != 0)
        {
            temp->next = 0;
        }
        
    }

    int size() {
        return this->nelem;
    }

    bool find(Data data) {
        DLNode<Data>* temp = getHead()->next;
        DLNode<Data>* tmp = getEnd()->pre;
        int check = 0;
        while(temp != 0 && tmp != 0) {
            if (temp->data == data || tmp->data == data)
            {
                return 1;
            }
            
            check = check + 2;
            if (check >= size())
            {
                return 0;
            }

            temp = temp->next;

            tmp = tmp->pre;
        }

        return 0;
    }

    Node<Data>* getHead() {
        return this->head;
    }

    Node<Data>* getEnd() {
        return this->end;
    }

    void traversal() {
        DLNode<Data>* temp = getHead()->next;

        while(temp != 0) {
            std::cout << "Node elem: " << temp->data << "   ";

            temp = temp->next;
        }
    }

    void backward() {
        DLNode<Data>* temp = getEnd()->pre;

        while(temp != 0) {
            std::cout << "Node elem: " << temp->data << "   ";

            temp = temp->pre;
        }
    }
};
#endif