#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
	//binary search tree
	Tree myTree;
	myTree.Insert(5);
	myTree.Insert(1);
	myTree.Insert(8);
	myTree.Insert(6);
	myTree.Insert(3);
	myTree.Print();

	Tree secondTree(myTree);
	secondTree.Print();

	int key;
	cout << "Input key: ";
	cin >> key;

	/*if (myTree.Find(key))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}*/

	secondTree.Erase(key);
	secondTree.Print();
	myTree.~Tree();
	myTree.Print();
}