/**
 * File name: AHCTree.cpp
 * Name: Yucheng Zhang & Yupei Zhu
 * Account ID: cs100scy & cs100sdb
 * Description: A hpp file definition the methods in AHCTree class
 * Date: 04/23/2016
 */
#ifndef AHCTree_HPP
#define AHCTree_HPP

#include "BitInputStream.hpp"
#include "BitOutputStream.hpp"
#include "AHCNode.hpp"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define ORDER 513
#define SIZE 256
class AHCTree
{
private:
    AHCNode* root;
    AHCNode* NYT;
    vector<AHCNode*> leaves;
    vector<AHCNode*> orderedNodes;
    
    /** Swap the two nodes.
     *  PRECONDITION: the two nodes to be swaped
     *  POSTCONDITION: the two nodes' parents and orders are swaped
     */
    void swap(AHCNode* n1, AHCNode* n2);

    /** Rebuild the trie after the nope inserted
     *  PRECONDITION: a node is inserted into the trie
     *  POSTCONDITION: the trie is updated according to weight and order
     */
    void rebuild(AHCNode* node);
    
    /** Insert a symbol in the current tree and rebuild the whole tree
     *  PRECONDITION: the symbol to added in the tree. 
     *  POSTCONDITION: the weight of the node that represent the symbol will
     *  increment or create the node if it does not exist. And rebuild the tree
     */
    void insert(unsigned char symbol);


public:
    
    explicit AHCTree() {
        
        NYT = new AHCNode(0, ORDER - 1, 0);
        root = NYT;
        
        leaves = vector<AHCNode*>(SIZE, (AHCNode*) 0);
        orderedNodes = vector<AHCNode*>(ORDER, (AHCNode*) 0);
        orderedNodes[ORDER - 1] = NYT;
    }

    /**
     *
     */
    ~AHCTree();


    /** the encode method that encode a certain symbol */
    void encode(unsigned char symbol, BitOutputStream& out);

    /** the decode method that read from the input file to output a symbol */
    int decode(BitInputStream& in);
    
};
#endif