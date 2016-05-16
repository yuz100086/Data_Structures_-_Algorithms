#ifndef ACNODE_HPP
#define  ACNODE_HPP
#define SIZE 256

#include <vector>
using namespace std;
class ACNode
{
public:
    vector<ACNode*>* children;
    ACNode* suff;
    ACNode* dict_suff;
    unsigned char symbol;
    bool is_word;
    string str;

    ACNode(unsigned char symbol,
           bool is,
           string str = "",
           ACNode* suff = 0,
           ACNode* dict_suff = 0
           ): suff(suff), dict_suff(dict_suff),
              symbol(symbol), is_word(is), str(str)
    {
        children = new vector<ACNode*>(SIZE);
    }
    
    ~ACNode(){delete children;}
    
};
#endif