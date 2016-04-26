/**
 * File name: HCTree.cpp
 * Name: Yucheng Zhang & Yupei Zhu
 * Account ID: cs100scy & cs100sdb
 * Description: The HCTree class. Contains implementation of methods.
 * Date: 04/13/2016
 */
#include "HCTree.hpp"
#include <stack>

/** this is the default destructor for the tree
 *
 */
HCTree::~HCTree() {
    deleteAll(root);
}

/** Use the Huffman algorithm to build a Huffman coding trie.
 *  PRECONDITION: freqs is a vector of ints, such that freqs[i] is 
 *  the frequency of occurrence of byte i in the message.
 *  POSTCONDITION:  root points to the root of the trie,
 *  and leaves[i] points to the leaf node containing byte i.
 */
void HCTree::build(const vector<int>& freqs) {
    // create a priority queue that holds HCNode ptrs
    std::priority_queue<HCNode*, vector<HCNode*>, HCNodePtrComp> pq;
    
    // symbol
    byte ch = 0;

    // for each loop push each element that has frequency higher than 0 to queue
    for(int elem: freqs) {
        if (elem != 0) {
            HCNode* temp = new HCNode(elem, ch, 0, 0, 0);
            leaves[(unsigned int)ch] = temp;
            pq.push(temp);
        }
        ch++;
    }
    
    // each time get two nodes from the queue
    while(pq.size() > 1) {
        // get two node ptr from the queue
        HCNode* tmp1 = pq.top();
        pq.pop();
        HCNode* tmp2 = pq.top();
        pq.pop();
        // the frequency of new node
        int frequency = tmp1->count + tmp2->count;
        
        // get the symbol to be the greater ascii symbol
        ch = tmp1->symbol;
        
        // create the new node
        HCNode* newNode = new HCNode(frequency, ch, tmp1, tmp2, 0);
        
        // update parent
        tmp1->p = newNode;
        tmp2->p = newNode;

        pq.push(newNode);
    }
    
    // the last node in the queue is root
    if (pq.size() == 0)
    {
        root = 0;
        return;
    }

    root = pq.top();
    pq.pop();

}

/** Write to the given BitOutputStream
 *  the sequence of bits coding the given symbol.
 *  PRECONDITION: build() has been called, to create the coding
 *  tree, and initialize root pointer and leaves vector.
 */
void HCTree::encode(byte symbol, BitOutputStream& out) const {
    // when there's only one node
    if (root->c1 == 0)
    {
        return;
    }

    // get the node from the leave vector
    HCNode* node = leaves[(unsigned int)symbol];
    stack<int> bits;
    // get the parent till root
    HCNode* parent = node->p;
    while(parent != 0) {
        if (parent->c0->symbol == node->symbol)
        {
            bits.push(0);
        }else {
            bits.push(1);
        }
        node = parent;
        parent = parent->p;
    }

    while(!bits.empty()){
        out.putBit(bits.top());
        bits.pop();
    }
}

/** Write to the given ofstream
 *  the sequence of bits (as ASCII) coding the given symbol.
 *  PRECONDITION: build() has been called, to create the coding
 *  tree, and initialize root pointer and leaves vector.
 *  THIS METHOD IS USEFUL FOR THE CHECKPOINT BUT SHOULD NOT 
 *  BE USED IN THE FINAL SUBMISSION.
 */
void HCTree::encode(byte symbol, ofstream& out) const {
    // when there's only one node
    if (root->c1 == 0)
    {
        out << 1;
        return;
    }

    // get the node from the leave vector
    HCNode* node = leaves[(unsigned int)symbol];
    stack<int> bits;
    // get the parent till root
    HCNode* parent = node->p;
    while(parent != 0) {
        if (parent->c0->symbol == node->symbol)
        {
            bits.push(0);
        }else {
            bits.push(1);
        }
        node = parent;
        parent = parent->p;
    }
    
    while(!bits.empty()){
        
        out<<bits.top();
        bits.pop();
    }
}

/** Return symbol coded in the next sequence of bits from the stream.
 *  PRECONDITION: build() has been called, to create the coding
 *  tree, and initialize root pointer and leaves vector.
 */
int HCTree::decode(BitInputStream& in) const {
    HCNode* temp = root;
    if (temp->c1 == 0)
    {
        //in.getBit();
        return temp->symbol;
    }

    char c = 0;
    while(temp->c0 != 0 && ((c = in.getBit())!=EOF)) {
        if (c == '0')
        {
            temp = temp->c0;
        }else if(c == '1'){
            temp = temp->c1;
        }
    }

    return temp->symbol;
}

/** Return the symbol coded in the next sequence of bits (represented as 
 *  ASCII text) from the ifstream.
 *  PRECONDITION: build() has been called, to create the coding
 *  tree, and initialize root pointer and leaves vector.
 *  THIS METHOD IS USEFUL FOR THE CHECKPOINT BUT SHOULD NOT BE USED
 *  IN THE FINAL SUBMISSION.
 */
int HCTree::decode(ifstream& in) const {
    HCNode* temp = root;
    if (temp->c1 == 0)
    {
        in.get();
        return temp->symbol;
    }

    char c = 0;
    while(temp->c0 != 0 && (c = in.get())) {
        
        if (c == '0')
        {
            temp = temp->c0;
        }else if(c == '1'){
            temp = temp->c1;
        }
    }

    return temp->symbol;
}

/** this private method is the helper method that delete all the allocated
 *  node memory locations
 */
void HCTree::deleteAll(HCNode* node) {
    if(node == 0)
        return;           // if node is null, return
      
    deleteAll(node->c0);   // delete the c0 subtree
      
    deleteAll(node->c1);  // delete the c1 subtree
      
    delete node;             // delete node
      
    return;
}
