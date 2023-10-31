#include<iostream>
#include"HashTable.h"

using namespace std;

const int n = 11;
const int m = 13;
const int p = 13;
const int data[n] = {16, 74, 60, 43, 54, 90, 46, 31, 29, 88, 77};
int main() {
	map1<int> my_map(m, p);
	cout<<my_map.size()<<endl;
	my_map[2] = 1;
	cout<<"insert (2, 1)"<<my_map[2]<<endl;
	my_map[2] = 3;
	cout<<"change (2, 1)->(2, 3)"<<my_map[2]<<endl;
	cout<<"remove key 2, 4:\t"<<my_map.remove(2)<<"\t"<<my_map.remove(4)<<endl;
	cout<<"insert a null key (3, null)"<<my_map[3]<<endl;
	
	for (int i=0; i<n; i++)
		my_map[data[i]] = i;
	cout<<"foreach: "<<endl;
	for (int i=0; i<n; i++)
		cout<<my_map[data[i]]<<"\t";
	cout<<endl;
	
	cout<<"allocate memory for pointer type"<<endl;
	int **a = new int*;
	*a = new int;
	**a = 2;
	cout<<sizeof(a)<<'\t'<<**a<<endl;
	delete *a;
	delete a;
	cout<<"after 'delete a', the value of a = "<<a<<endl;
	a = nullptr;
	cout<<"reset value a = nullptr "<<"nullptr = "<<a<<endl;
	
	int **b = new int*[10];
	for (int i=0; i<10; i++) {
		b[i] = new int;
		*b[i] = i*i;
	}
	for (int i=0; i<10; i++) 
		cout<<"address: "<<b[i]<<"  value: "<<*b[i]<<endl;
	for (int i=0; i<10; i++)
		delete b[i];
	delete [] b;
		
	
	return 0;
}