#include <iostream>
#include "linearList.h"
//#include "linearList.cpp"

using namespace std;

int main(){
	SqList<int> L(20);
	
	cout <<"empty: "<<L.empty()<<endl;
	L.insert(1, 520);
	cout <<"empty: "<<L.empty()<<endl;
	
	for (int i=2;i<=20;i++){
		L.insert(i, 42);
	}
	cout <<"length: "<<L.length()<<endl;
	L.disp();
	
	int e;
	if (!L.erase(2, e)){
		cout <<"erase error"<<endl;
	}
	else{
		cout <<"erase element: "<<e<<" length: "<<L.length()<<endl;
	}
	
	if (!L.get(1, e)){
		cout <<"get error"<<endl;
	}
	else{
		cout <<"get element: "<<e<<endl;
	}
	
	int idx = L.locate(e);
	if (!idx){
		cout <<"no matched element"<<endl;
	}
	else{
		cout <<"location of element "<<e<<" is "<<idx<<endl;
	}
	
	
	//µ¥Á´±í²âÊÔ
	int a[5] = {1, 2, 3, 4, 5};
	LinkNode<int> H(a, 5, true);
	
	//Ë«Á´±í²âÊÔ
	int d[5] = {1,2,3,4,5}, e1;
	DList<int> D1(d,5), D2(d,5,false);
	
	D1.disp();
	D2.disp();
	
	cout <<"get: "<<endl;
	for(int i=0;i<6;i++)
	{
		if (D1.get(i, e1))
			cout <<i<<"\t"<<e1<<endl;
	}
	
	cout <<"locate: "<<endl;
	for (int i=0;i<5;i++)
	{
		idx = D1.locate(d[i]);
		cout <<idx<<"\t"<<d[i]<<endl;
	}
	
	cout <<"insert: "<<endl;
	for (int i=1;i<6;i++)
	{
		D1.insert(i, d[i-1]);
	}
	D1.insert(11, 6);
	D1.disp();
	
	cout <<"erase: "<<endl;
	for (int i=1;i<6;i++)
	{
		D1.erase(1, e1);
	}
	D1.disp();
	
	system("pause");
	
	return 0;
}