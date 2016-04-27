/**
 *  Filename: TSTTree.hpp
 *  Name: Yucheng Zhang
 *  Github: yuz100086
 *  Description: This is the file TSTTree.hpp. It contains the definition of the
 *               ternary search tree.
 *  Date: 04/25/16
 */

#ifndef TSTTREE_HPP
#define TSTTREE_HPP

#include <string>
#include "TSTNode.hpp"

class TSTTree
{
private:
    TSTNode* root;
    
    /**
      * The helper method for destructor
      */
    static void DeleteAll(TSTNode* node);
    
    /**
      * the helper method used to make insert method.
      */
    TSTNode* insertDown(TSTNode* node, const string& word, 
                    const int& num, int index);
public:
    TSTTree() : root(0) {}
    ~TSTTree();
    
    /** 
      * this is the find method that takes a string, and find in the 
      * ternary search tree. If the string is in the tree, return true, 
      * otherwise false.
      */
    bool find(const string& word) const;
    
    /**
      * this is the insert method that insert a word into the 
      * ternary search tree. If the word is not in the tree, create
      * the word, otherwise update the number it associates with.
      */
    void insert(const string& word, const int& num);


};
#endif 