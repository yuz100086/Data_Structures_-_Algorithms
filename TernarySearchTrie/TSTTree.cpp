#include "TSTTree.hpp"

TSTTree::~TSTTree() {
    DeleteAll(root);
}
/** 
  * this is the find method that takes a string, and find in the 
  * ternary search tree. If the string is in the tree, return true, 
  * otherwise false.
  */
bool TSTTree::find(const string& word) const {
    TSTNode* temp = root;
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
    root = insertDown(root, word, num, 0);
}

/**
  * the helper method used to make insert method.
  */
TSTNode* TSTTree::insertDown(TSTNode* node, const string& word, 
                        const int& num, int index) {
    if (node == 0)
    {
        node = new TSTNode(word[index], 0);
    }

    if (node->symbol > word[index])
    {
        node->left = insertDown(node->left, word, num, index);
    }else if (node->symbol < word[index])
    {
        node->right = insertDown(node->right, word, num, index);
    }else if (index < word.length()-1)
    {
        node->down = insertDown(node->down, word, num, index+1);
    }else{
        node->count = num;
    }

    return node;
    
}

/**
  * The helper method for destructor
  */
void TSTTree::DeleteAll(TSTNode* node) {
    if (node == 0)
    {
        return;
    }

    DeleteAll(node->left);

    DeleteAll(node->right);

    DeleteAll(node->down);

    delete node;
}