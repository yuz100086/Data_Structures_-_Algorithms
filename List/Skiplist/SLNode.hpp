/**
 * File name: SLNode.hpp
 * Name: Yucheng Zhang & Yupei Zhu
 * Account ID: cs100scy & cs100sdb
 * Description: The SL node class.
 * Date: 04/02/2016
 */


#ifndef SLNODE_HPP
#define SLNODE_HPP
#include <iostream>
#include <iomanip>

template<typename Data>
class SLNode {
    
public:
    
    /** Constructor.  Initialize a SLNode with the given Data item,
     *  no parent, and no children.
     */
    SLNode(const Data & d) : data(d) {
        right = 0;
        down = 0;
    }
    
    SLNode<Data>* right;
    SLNode<Data>* down;
    Data const data;   // the const Data in this node.
    
};

#endif // SLNODE_HPP
