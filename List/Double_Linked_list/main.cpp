#include <iostream>
#include "DLTree.hpp"
using namespace std;
int main(int argc, char const *argv[])
{
	DLTree<int>* list = new DLTree<int>();
    
    for (int i = 10; i < 20; i+=2)
    {
    	list->insert(i);
    }

    list->traversal();

    for (int i = 0; i < 10; ++i)
    {
    	cout << i << ": " << list->find(i) << endl;
    }

    for (int i = 10; i < 20; ++i)
    {
    	cout << i << ": " << list->find(i) << endl;
    }

    for (int i = 10; i < 12; ++i)
    {
    	list->deleteFirst();
    }
	list->traversal();
	list->backward();

	for (int i = 0; i < 3; ++i)
	{
		list->deleteLast();
	}

	list->traversal();
	list->backward();

	for (int i = 100; i > 90; --i)
	{
		list->insertLast(i);
	}

	list->traversal();
	list->backward();

	delete list;

	return 0;
}