#include "DLTree.hpp"

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

void DLTree::insert(Data data) {
    Node* hed = getHead();
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

void DLTree::deleteFirst() {
    Node* hed = getHead();

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
        temp->pre = hed;
    }
}

void insertLast(Data data) {
    Node* hed = getEnd();
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
    Node* hed = getEnd();

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
        temp->next = hed;
    }
    
}

int DLTree::size() {
    return this->nelem;
}

bool DLTree::find(Data data) {
    DLNode<Data>* temp = getHead()->next;
    while(temp != 0) {
        if (temp->data == data)
        {
            return 1;
        }

        temp = temp->next
    }

    return 0;
}

Node* DLTree::getHead() {
    return this->head;
}

Node* DLTree::getEnd() {
    return this->end;
}
