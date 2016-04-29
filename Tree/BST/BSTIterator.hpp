/**
 * File name: BSTIterator.hpp
 * Name: Yucheng Zhang & Yupei Zhu
 * Account ID: cs100scy & cs100sdb
 * Description: The BSTIterator class. Implements the basic methods of the 
 *              iterator of BST.
 * Date: 04/02/2016
 */
#ifndef BSTITERATOR_HPP
#define BSTITERATOR_HPP
#include "BSTNode.hpp"
#include <list>
#include <iterator>

template<typename Data>
class BSTIterator : public std::iterator<std::input_iterator_tag,Data> {

private:

  BSTNode<Data>* curr;

public:

  /** Constructor.  Use the argument to initialize the current BSTNode
   *  in this BSTIterator.
   */
  BSTIterator(BSTNode<Data>* curr) {
      this->curr = curr;
  }

  /** Dereference operator. */
  Data operator*() const {
      if(curr == 0)
          return 0;
      return curr->data;
  }
  
  /** Pre-increment operator. */
  BSTIterator<Data>& operator++() {
      curr = curr->successor();
      return *this;
  }

  /** Post-increment operator. */
  BSTIterator<Data> operator++(int) {
      BSTIterator before = BSTIterator(curr);
      ++(*this);
      return before;
  }

  /** Equality test operator. */
  bool operator==(BSTIterator<Data> const & other) const {
      // when both null
      if(other.curr == 0 && curr == 0)
          return true;

      // when either null, not both
      if(other.curr == 0 || curr == 0)
          return false;
      
      // when data are equal
      if(!(curr->data < other.curr->data))
          if(!(other.curr->data < curr->data))
              return true;
      return false;
  }

  /** Inequality test operator. */
  bool operator!=(BSTIterator<Data> const & other) const {
      // when both null
      if(other.curr == 0 && curr == 0)
          return false;

      // when either null, not both
      if(other.curr == 0 || curr == 0)
          return true;
      
      // when data are equal
      if(curr->data < other.curr->data ||
         other.curr->data < curr->data)
            return true;
      return false;
  }

};

#endif //BSTITERATOR_HPP
