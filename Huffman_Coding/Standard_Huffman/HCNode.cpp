/**
 * File name: HCNode.cpp
 * Name: Yucheng Zhang & Yupei Zhu
 * Account ID: cs100scy & cs100sdb
 * Description: The HCNode class. Contains implementation of methods.
 * Date: 04/13/2016
 */
#include "HCNode.hpp"

/** Less-than comparison, so HCNodes will work in std::priority_queue
 *  We want small counts to have high priority.
 *  And we want to break ties deterministically.
 */
bool HCNode::operator<(const HCNode& other) {
    // first compare count, then ascii symbol
    if (count != other.count)
    {
        return count > other.count;
    }

    return symbol < other.symbol;
}

/** This comp method compare two HCNode pointers
 */
bool comp(HCNode* one, HCNode* other) {
    return (*one) < (*other); 
}
