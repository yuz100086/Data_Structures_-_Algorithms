#include "TSTTree.hpp"

/** 
  * this is the find method that takes a string, and find in the 
  * ternary search tree. If the string is in the tree, return true, 
  * otherwise false.
  */
bool TSTTree::find(const string& word) const {
    TSTNode* temp = this->root;
    int size = word.length();
    int counter = 0;

    while (counter < size)
    {
        if (temp == 0)
        {
            return 0;
        }

        if (word[counter] == temp->symbol)
        {
            temp = temp->down;
            counter++;
        }else if (word[counter] < temp->symbol)
        {
            temp = temp->right;
        }else{
            temp = temp->left;
        }
    }

    return 1;
}
    
/**
  * this is the insert method that insert a word into the 
  * ternary search tree. If the word is not in the tree, create
  * the word, otherwise update the number it associates with.
  */
void TSTTree::insert(const string& word, const int& num) {
    TSTNode* temp = this->root;
    TSTNode* pretmp = temp;
    int size = word.length();
    int counter = 0;

    while (counter < size) {
        if (temp == 0)
        {
            string str = word.substr(counter, size-counter);
            insertDown(pretmp, str, num);
            return;
        }

        if (word[counter] == temp->symbol)
        {
            pretmp = temp;
            temp = temp->down;
            counter++;
        }else if (word[counter] < temp->symbol)
        {
            pretmp = temp;
            temp = temp->right;
        }else{
            pretmp = temp;
            temp = temp->left;
        }
    }

    pretmp->count = num;
}

/**
  * the helper method used to make insert method.
  */
void TSTTree::insertDown(TSTNode* node, const string& word, const int& num) {
    
}