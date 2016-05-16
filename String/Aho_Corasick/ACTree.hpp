#ifndef ACTREE_HPP
#define ACTREE_HPP

#include <string>
#include <utility>
#include "ACNode.hpp"
using namespace std;
class ACTree
{
private:
    static void deleteAll(ACNode* node);

    void updateNode(ACNode* node, string str);

    void updateDict(ACNode* node);
public:
    ACNode* root;

    ACTree() {root = new ACNode(0,0);}
    ~ACTree();
    
    bool insert(string word);

    vector<pair<ACNode*, int>> find(string word);

    void updateSuff();

    void updateDict_Suff();


};
#endif