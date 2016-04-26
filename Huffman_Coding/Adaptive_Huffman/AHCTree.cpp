/**
 * File name: AHCTree.hpp
 * Name: Yucheng Zhang & Yupei Zhu
 * Account ID: cs100scy & cs100sdb
 * Description: A cpp file implements the methods in AHCTree class
 * Date: 04/23/2016
 */
#define EIGHT 8
#include "AHCTree.hpp"


/** Insert a symbol in the current tree and rebuild the whole tree
 *  PRECONDITION: the symbol to added in the tree. 
 *  POSTCONDITION: the weight of the node that represent the symbol will
 *  increment or create the node if it does not exist. And rebuild the tree
 */
void AHCTree::insert(unsigned char symbol) {
    // check if there is a node for the symbol
    if (leaves[(unsigned int) symbol] != 0)
    {
        // straightly rebuild from the node
        rebuild(leaves[(unsigned int)symbol]);
        return;
    }
    
    // create the new NYT node and new node contains the symbol
    AHCNode* myNYT = new AHCNode(0, NYT->order-2, 0);
    AHCNode* newNode = new AHCNode(0, NYT->order-1, symbol);
    
    // assign the new node to the leaves vector
    leaves[(unsigned int)symbol] = newNode;
    // assign the two nodes to the orderedNodes vector
    orderedNodes[NYT->order-1] = newNode;
    orderedNodes[NYT->order-2] = myNYT;
    // change their parent to NYT
    newNode->parent = myNYT->parent = NYT;
    // change children of NYT
    NYT->left = myNYT;
    NYT->right = newNode;
    
    // change NYT to myNYT
    NYT = myNYT;
    // rebuild the tree from newNode
    rebuild(newNode);
}

/** Swap the two nodes.
 *  PRECONDITION: the two nodes to be swaped
 *  POSTCONDITION: the two nodes' parents and orders are swaped
 */
void AHCTree::swap(AHCNode* n1, AHCNode* n2){
    // get he two node 
    AHCNode** p1 = n1->parent->left == n1 ?
                    &(n1->parent->left) : &(n1->parent->right);
    AHCNode** p2 = n2->parent->left == n2 ?
                    &(n2->parent->left) : &(n2->parent->right);
    
    // swap the two node
    *p1 = n2;
    *p2 = n1;
    
    // update the parents
    AHCNode* parent = n1->parent;
    n1->parent = n2->parent;
    n2->parent = parent;
    
    // update order
    int temp = n1->order;
    n1->order = n2->order;
    n2->order = temp;
    
    // update the order's node
    orderedNodes[n1->order] = n1;
    orderedNodes[n2->order] = n2;

}

/** Rebuild the trie after the nope inserted
 *  PRECONDITION: a node is inserted into the trie
 *  POSTCONDITION: the trie is updated according to weight and order
 */
void AHCTree::rebuild(AHCNode* node) {
    AHCNode* temp = node;
    // go from the current node to root to update everyone in the path
    while(temp != root){
        // the order that will be able to swap
        int orderIdx = ORDER - 2;
        // get to the highest order node with same weight
        while(orderedNodes[orderIdx]->weight != temp->weight){
            orderIdx--;
        }
        
        // swap the nodes
        if(temp != orderedNodes[orderIdx] &&
           orderedNodes[orderIdx] != temp->parent)
            swap(temp, orderedNodes[orderIdx]);
        
        // increment weight
        temp->weight++;
        temp = temp->parent;
    }
    // update root weight
    root->weight++;
}

/** the encode method that encode a certain symbol */
void AHCTree::encode(unsigned char symbol, BitOutputStream& out) {
    // get the symbol node if valid, otherwise NYT
    AHCNode* node = (leaves[(unsigned int) symbol] != 0)? 
                    leaves[(unsigned int)symbol] : NYT;
    
    stack<int> bits;
    // get the parent till NYT
    AHCNode* parent = node->parent;
    while(parent != 0) {
        if (parent->left == node)
        {
            bits.push(0);
        }else {
            bits.push(1);
        }
        node = parent;
        parent = parent->parent;
    }
    
    // write the path of NYT
    while(!bits.empty()){
        out.putBit(bits.top());
        bits.pop();
    }
    
    // if the symbol is new, put the char
    if (leaves[(unsigned int) symbol] == 0)
    {
            out.putChar(symbol);
    }
    
    // insert the symbol
    insert(symbol);
            
}

/** the decode method that read from the input file to output a symbol */
int AHCTree::decode(BitInputStream& in){
    AHCNode* temp = root;
    unsigned char ch;
    unsigned char newChar;
    int bit = 0;
    
    // get bit and go to the node
    while(temp->left != 0 && (bit = in.getBit())!=EOF){
        if(bit == 1){
            temp = temp->right;
        }else{
            temp = temp->left;
        }
    }
    
    if(bit == EOF){
        return EOF;
    }
    
    // if the node is NYT then insert the char and return char 
    if(temp == NYT){
        newChar = in.getChar();
        insert(newChar);
        return newChar;
    }
    ch = temp->symbol;
    insert(ch);
    return ch;
}

/**
 * the default destructor or the tree
 */
AHCTree::~AHCTree() {
    // traverse the orderedNodes vecter and delete each existing node
    for(int i = 0; i < ORDER; i++){
        if(orderedNodes[i]!=0)
            delete orderedNodes[i];
    }
}