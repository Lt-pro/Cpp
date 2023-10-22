#include <iostream>
#include "tree.h"

using namespace std;

const int n = 10;
int main()
{
	BST<int, int> bst;
	
	const int keys[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	const int values[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	for (int i=0;i<n;i++)
	{
		bst.insert(keys[i], values[i]);
		cout <<"Element "<<i+1<<"\t: "<<"key = "<<keys[i]<<"\tvalue = "<<values[i]<<"\ttotals = "<<bst.length()<<endl;
	}
	int e;
	cout <<"search keys[1], true value = "<<values[1]<<endl;
	if (bst.search(keys[1], e))
		cout <<"searched value of keys[1] = "<<e<<endl;
	else
		cout <<"no keys[1]"<<endl;
	
	cout <<"search keys[n], true value = NULL"<<endl;
	if (bst.search(11, e))
		cout <<"searched value of keys[n] = "<<e<<endl;
	else
		cout <<"no keys[n]"<<endl;

	cout <<"delete keys[0] test"<<endl;
	if (bst.erase(keys[0]))
		cout <<"delete keys[0] successfully"<<"\tsearch keys[0]: "<<bst.search(keys[0], e)<<endl;
	cout <<"delete keys[n] test"<<endl;
	if (!bst.erase(11))
		cout <<"error key input"<<endl;
	
	
	AVL<int, int> avl;
	cout <<"AVL tree"<<endl;
	for (int i=0;i<n;i++)
	{
		avl.insert(keys[i], values[i]);
		cout <<"Element "<<i+1<<"\t: "<<"key = "<<keys[i]<<"\tvalue = "<<values[i]<<"\ttotals = "<<avl.length()<<"\theight = "<<avl.height()<<endl;
	}
	
	cout <<"search keys[1], true value = "<<values[1]<<endl;
	if (avl.search(keys[1], e))
		cout <<"searched value of keys[1] = "<<e<<endl;
	else
		cout <<"no keys[1]"<<endl;
	cout <<"search keys[n], true value = NULL"<<endl;
	if (avl.search(11, e))
		cout <<"searched value of keys[n] = "<<e<<endl;
	else
		cout <<"no keys[n]"<<endl;
	
	if (avl.erase(keys[0]))
		cout <<"true"<<endl;
	else
		cout <<"false"<<endl;
	for (int i=1;i<n;i++)
	{
		avl.erase(keys[i]);
		cout <<"erase Element "<<i+1<<"\t: "<<"key = "<<keys[i]<<"\tvalue = "<<values[i]<<"\ttotals = "<<avl.length()<<"\theight = "<<avl.height()<<endl;
	}
	return 0;
}