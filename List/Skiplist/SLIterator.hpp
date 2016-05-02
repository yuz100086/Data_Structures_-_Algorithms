/**
 * File name: SLIterator.hpp
 * Name: Yucheng Zhang & Yupei Zhu
 * Account ID: cs100scy & cs100sdb
 * Description: The SLIterator class. Implements the basic methods of the
 *              iterator of skip list.
 * Date: 04/02/2016
 */
#ifndef SLITERATOR_HPP
#define SLITERATOR_HPP
#include "SLNode.hpp"
#include <list>
#include <iterator>

template<typename Data>
class SLIterator : public std::iterator<std::input_iterator_tag,Data> {
    
private:
    
    int compareTime;
    
public:
    
    /** Constructor.  Use the argument to initialize the current BSTNode
     *  in this SLIterator.
     */
    SLNode<Data>* curr;
    SLIterator(SLNode<Data>* curr, int time) {
        this->curr = curr;
        compareTime = time;
    }
    
    /** the getter for compareTime */
    int getTime() {return this->compareTime;}
    
    /** Dereference operator. */
    Data operator*() const {
        if(curr == 0)
            return 0;
        return curr->data;
    }
    
    /** Pre-increment operator. */
    SLIterator<Data>& operator++() {
        curr = curr->right;
        return *this;
    }
    
    /** Post-increment operator. */
    SLIterator<Data> operator++(int) {
        SLIterator before = SLIterator(curr);
        ++(*this);
        return before;
    }
    
    /** Equality test operator. */
    bool operator==(SLIterator<Data> const & other) const {
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
    bool operator!=(SLIterator<Data> const & other) const {
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

#endif //SLITERATOR_HPP
