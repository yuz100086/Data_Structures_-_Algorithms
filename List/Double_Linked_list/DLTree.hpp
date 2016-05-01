##ifndef DLTREE_HPP
#define  DLTREE_HPP

#include "DLNode.hpp"

class DLTree
{
private:
	DLNode* head;
	DLNode* end;
	int nelem;

    static void DeleteAll(DLNode* node);
public:
    DLTree(DLNode* head = 0, 
    	   DLNode* end = 0, 
    	   n = 0) : head(head), end(end), nelem(n){}
    ~DLTree();
    
    void insert(Data data);

    int size();

    bool find(Data data);

    void delete();
};
#endif