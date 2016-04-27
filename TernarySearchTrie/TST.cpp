/**
  * Filename: TST.cpp
  * Name: Yucheng Zhang
  * Github: yuz100086
  * Description: This is the main for the ternary search tree.
  */
#include <iostream> 
#include <string>  
#include "TSTTree.hpp"
#include "TSTNode.hpp"  
int main(int argc, char const *argv[])
{
	TSTTree* tree = new TSTTree();
	cout << "Please insert any words.";
    
    string word;
	while(word != "q") {
        getline (cin, word);
        tree->insert(word, 5);
	}

	cout << tree->find("abc");

	delete tree;
	return 0;
}