/**
 * File name: BSTNode.hpp
 * Name: Yucheng Zhang & Yupei Zhu
 * Account ID: cs100scy & cs100sdb
 * Description: The BST node class. Contains successor() method to get 
 *              the successor of certain node.
 * Date: 04/02/2016
 */


#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>

template<typename Data>
class BSTNode {

public:

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d) : data(d) {
      left = right = parent = 0;
  }

  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;
  Data const data;   // the const Data in this node.

  /** Return the successor of this BSTNode in a BST, or 0 if none.
   ** PRECONDITION: this BSTNode is a node in a BST.
   ** POSTCONDITION:  the BST is unchanged.
   ** RETURNS: the BSTNode that is the successor of this BSTNode,
   ** or 0 if there is none.
   */
  BSTNode<Data>* successor() {

      // create node pointer to the parent
      BSTNode<Data>* suc = parent;

      // when the node has no right child
      if(right == 0){

          // go the the parent that greater than it
          while( suc != 0 && suc->data < data )
              suc = suc->parent;
          return suc;
      }
      
      
      suc = right;                // when it has right child
      while ( suc->left != 0)     // traverse the right sub tree to
          suc = suc->left;        // get the left most node
      
      return suc;
      
  }

}; 

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
