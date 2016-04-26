/**
 * File name: AHCNode.hpp
 * Name: Yucheng Zhang & Yupei Zhu
 * Account ID: cs100scy & cs100sdb
 * Description: The AHCNode header class. Contains the constructor and its fields
 * Date: 04/23/2016
 */
#ifndef AHCNODE_HPP
#define AHCNODE_HPP

typedef unsigned char byte;
/** A class, instances of which are nodes in an AHCTree.
 */
class AHCNode
{
    
public:
    byte symbol;          // byte in the file we're keeping track of
    int weight;           // the weight of the node (num of the byte)
    int order;            // the order of the node
    AHCNode* left;        // point to the left child
    AHCNode* right;       // point to the right child
    AHCNode* parent;      // point to the parent
    
    AHCNode(int weight,
            int order,
            byte symbol,
            AHCNode* left = 0,
            AHCNode* right = 0,
            AHCNode* parent = 0)
    : weight(weight), order(order), symbol(symbol), left(left),
    right(right), parent(parent) { }
    
};

#endif