/**
 * File name: BST.hpp
 * Name: Yucheng Zhang & Yupei Zhu
 * Account ID: cs100scy & cs100sdb
 * Description: The BST class. Implements the basic methods of a binary
 *              search tree.
 * Date: 04/02/2016
 */
#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>

template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;

  /** Height of this BST. */
  unsigned int iheight;
  
public:

  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(nullptr), isize(0), iheight(0) {  }


  /** Default destructor.
      Delete every node in this BST.
   */
  virtual ~BST() {
      deleteAll(root);
  }

  /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return  true if the item was added to this BST
   *  as a result of this call to insert,
   *  false if an item equal to this one was already in this BST.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=)  For the reasoning
   *  behind this, see the assignment writeup.
   */
  virtual bool insert(const Data & item) {

      // check the root, if it is null insert here
      if (root == 0){
          root = new BSTNode<Data>(item);
          isize = 1;
          iheight = 0;
          return true;
      }
      
      // create node pointers 
      BSTNode<Data>* temp = root;
      BSTNode<Data>* parent = 0;
      
      unsigned int height = 0;

      // travese to the leaf
      while(temp != 0){
          height++;
          if( temp->data < item ){
              parent = temp;
              temp = temp->right;
          }else if(item < temp->data){
              parent = temp;
              temp = temp->left;
          }else{
              return false;
          }
      }
      
      // update height 
      if(height > iheight)
          iheight = height;
      
      // insert the new node
      isize ++;
      temp = new BSTNode<Data>(item);
      temp->parent = parent;
      
      // update the prevois node
      if(parent->data < item)
          parent->right = temp;
      else
          parent->left = temp;
      return true;
  }


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=).  For the reasoning
   *  behind this, see the assignment writeup.
   */
  iterator find(const Data & item) const {
      // create a temporary node pointer
      BSTNode<Data>* temp = root;

      // traverse to the next node by comparing with the item
      while(temp != 0){

          // when node smaller than item, go to right
          if( temp->data < item ){
              temp = temp->right;
          }else if(item < temp->data){  // go to left
              temp = temp->left;
          }else{  // when the item is found return iterator
              return typename BST<Data>::iterator(temp);
          }
      }

      // not found
      return typename BST<Data>::iterator(0);
  }

  
  /** Return the number of items currently in the BST.
   */
  unsigned int size() const {
      return isize;
  }
  
  /** Return the height of the BST.
   */
  unsigned int height() const {
      return iheight;
  }


  /** Return true if the BST is empty, else false.
   */
  bool empty() const {
      if(isize == 0)
          return true;
      return false;
  }

  /** Return an iterator pointing to the first item in the BST (not the root).
   */
  iterator begin() const {
      BSTNode<Data>* temp = root;
      if(temp == 0)
          return typename BST<Data>::iterator(0);
      while(temp->left != 0)
          temp = temp->left;
      return typename BST<Data>::iterator(temp);
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
      return typename BST<Data>::iterator(0);
  }

  /** Perform an inorder traversal of this BST.
   */
  void inorder() const {
      inorder(root);
  }


private:

  /** Recursive inorder traversal 'helper' function */

  /** Inorder traverse BST, print out the data of each node in ascending order.
   *  Implementing inorder and deleteAll base on the pseudo code is an easy 
   *  way to get started.
   */
  void inorder(BSTNode<Data>* n) const {
    /* Pseudo Code:
       if current node is null: return;
       recursively traverse left sub-tree
       print current node data
       recursively traverse right sub-tree
     */

      if(n == 0)    // if n is null return
          return;
      
      inorder(n->left); // traverse the left subtree
      
      std::cout << n->data << std::endl;  // print the data in n
      
      inorder(n->right);    // traverse the right subtree
  }

  /** Find the first element of the BST
   */ 
  static BSTNode<Data>* first(BSTNode<Data>* root) {
    if(root == 0) return 0;
    while(root->left != 0) root = root->left;
    return root;
  }

  /** do a postorder traversal, deleting nodes
   */
  static void deleteAll(BSTNode<Data>* n) {
    /* Pseudo Code:
       if current node is null: return;
       recursively delete left sub-tree
       recursively delete right sub-tree
       delete current node
     */

      if(n == 0)
          return;           // if n is null, return
      
      deleteAll(n->left);   // delete the left subtree
      
      deleteAll(n->right);  // delete the right subtree
      
      delete n;             // delete n
      
      return;
  }


 };


#endif //BST_HPP
