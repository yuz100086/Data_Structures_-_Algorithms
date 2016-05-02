/**
 * File name: skiplist.hpp
 * Name: Yucheng Zhang & Yupei Zhu
 * Account ID: cs100scy & cs100sdb
 * Description: The skiplist class. Implements the basic methods of a skiplist
 * Date: 04/02/2016
 */
#ifndef SKIPLIST_HPP
#define SKIPLIST_HPP
#include "SLNode.hpp"
#include "SLIterator.hpp"
#include <iostream>
#include <vector>

#define TWO 2
using namespace std;

template<typename Data> class skiplist {
    
public:
    /** define iterator as an aliased typename for BSTIterator<Data>. */
    typedef SLIterator<Data> iterator;
    
    // other public member variables
    SLNode<Data> * head;
    unsigned int size;
    
    /**
     * the constructor for the skiplist object
     */
    skiplist( const Data& item ){
        size = 0;
        head = new SLNode<Data>(item);
        
        // set the random's seed for insert
        srand((unsigned int)time(NULL));
    }
    
    /**
     * the destructor used for skiplist
     */
    virtual ~skiplist() {
        deleteAll(head);
    }
    
    /**
     * the insert method that insert a data item into the skiplist
     * if the item is already in the list, return false.
     * otherwise return true.
     *
     */
    virtual bool insert(const Data& item) {
        // the temporary node used to keep track
        SLNode<Data>* temp = head;
        
        // the list used to store the position where the node will insert if
        // insert to higher level
        vector<SLNode<Data>*> list;
        
        // while loop goes to the lowest level
        while(temp != 0){
            
            // when right is nullptr, which means the end of this level
            // add the position and go down
            if(temp->right == 0){
                list.push_back(temp);
                temp = temp->down;
                continue;
            }
                
            // compare the item with node
            if( temp->right->data < item ){ 
                // item greater than node, go to right
                temp =temp->right;
                continue;
            }else if(item < temp->right->data){
                // item smaller than node, go down level
                list.push_back(temp);
                temp = temp->down;
                continue;
            }else{
                return false;
            }
        }
        
        // insert item by calling helper method
        insertNode(list, item);
        size++;
        return true;
    }
    
    /**
     * the find method that find the item in the skiplist.
     * if the item is found, return a iterator point to the node,
     * otherwise return a iteratot point ot the end
     */
    iterator find(const Data& item) const {
        int time = 0;
        SLNode<Data>* temp = head;
        
        // the loop go down each level
        while(temp != 0){
            // reach the rightmost of the level, go down
            if(temp->right == 0){
                temp = temp->down;
                continue;
            }
            
            // compare node with item
            time++;
            if( temp->right->data < item ){ // item > data
                temp = temp->right;
                continue;
            }
            time++;
            if( item<temp->right->data ){ // item < data
                temp = temp->down;
                continue;
            }else{ // item == data, found
                return typename skiplist<Data>::iterator(temp->right, time);
            }
            
        }
        
        // not found
        return typename skiplist<Data>::iterator(0, time);
    }
    
private:
    
    /**
     * the helper method for insert method, first add the item at bottom
     * then use coinFilp method to check whether add at upper level.
     */
    void insertNode(vector<SLNode<Data>*> & list, const Data & item) {
        // get the first position to insert
        SLNode<Data>* temp = list.back();
        
        // create the new node
        SLNode<Data>* newNode = new SLNode<Data>(item);
        
        // update links
        newNode->right = temp->right;
        temp->right = newNode;
        
        // delete the position
        list.pop_back();
        
        // insert in upper level if coinFlip return true
        while (coinFlip()) {
            // add to level that not created yet
            if (list.empty()) {
                // create new head
                SLNode<Data>* newH = new SLNode<Data>(item);
                // update head links
                newH->down = head;
                head = newH;
                
                // create new node
                SLNode<Data>* newN = new SLNode<Data>(item);
                // update links
                newH->right = newN;
                newN->down = newNode;
                newN->right = 0;
                newNode = newN;
            }else {  // add to exist level with the position in list
                // create the new node
                SLNode<Data>* newN = new SLNode<Data>(item);
                // get position
                temp = list.back();
                // update links
                newN->right = temp->right;
                temp->right = newN;
                newN->down = newNode;
                newNode = newN;
                
                // delete position
                list.pop_back();
            }
            
        }
    }
    
    /**
     * the coinFlip function that act as a coin to get random true or false
     */
    bool coinFlip() {
        
        // get random number between 0-1000
        int num = rand()%TWO;
        // true if in 0-1
        if (num < 1)
            return true;
        
        return false;
    }
    
    /**
     * the deleteAll functions deleting all the memory allocated
     */
    static void deleteAll(SLNode<Data>* head) {
        // temporary nodes
        SLNode<Data>* t1 = head;
        SLNode<Data>* t2 = head;
        SLNode<Data>* t3 = head;
        
        // if the head is not nullptr, otherwise the list is empty
        while(t1 != 0){
            // set t2 to t1 to delete the level of nodes
            t2 = t1;
            // t1 to the next level
            t1 = t1->down;
            
            // loop to delete the level
            while(t2 != 0){
                // delete the node and go to the next right one
                t3 = t2;
                t2 = t2->right;
                delete t3;
            }
            
        }
        
        return;
    }
};

#endif //SKIPLIST_HPP
