#ifndef DLNODE_HPP
#define DLNODE_HPP

template <typename Data>
class DLNode
{
private:
    
public:
    Data data;
    DLNode<Data>* next;
    DLNode<Data>* pre;
    DLNode(Data data, 
           DLNode<Data>* ne, 
           DLNode<Data>* pre) : data(data), next(ne), pre(pre){}

    DLNode<Data>* getNext() {
        return this->next;
    }

	DLNode<Data>* getPre() {
	    return this->pre;
	}

	bool operator<(DLNode<Data>* other) {
	    if (this->data < other->data)
	    {
	        return 1;
	    }

	    return 0;
	}
    
};
#endif