#include <iostream>
#include "tree.h"


using namespace std;


int main()
{
	char bt[] = "A(B(D(,G)),C(E,F))";
	BTNode<char> *b;
	
	StrBTree tree(bt);
	cout <<bt<<endl;
	tree.disp();
	cout <<"height of tree: "<<tree.height()<<endl;
	b = tree.locate('D');
	cout <<"Location of element D: "<<b<<'\t'<<b->data<<endl;
	
	
	create(b, bt);
	preorder1(b);
	cout <<endl;
	preorder2(b);
	cout <<endl;
	
	return 0;
}