#include<iostream>
#include"HashTable.h"

using namespace std;

const int n = 11;
const int m = 13;
const int p = 13;
const int data[n] = {16, 74, 60, 43, 54, 90, 46, 31, 29, 88, 77};

int main(){
	map2<int> my_map(m, p);
	my_map[2] = 1;
	cout<<"insert (2, 1)"<<my_map[2]<<" n = "<<my_map.size()<<endl;
	cout<<"insert a null key (3, null)"<<my_map[3];
	cout<<"\tn = "<<my_map.size()<<endl;
	my_map[2] = 3;
	my_map[2] = 3;
	cout<<"change (2, 1)->(2, 3)"<<my_map[2];
	cout<<" n = "<<my_map.size()<<endl;
	cout<<"remove key 2:\t"<<my_map.remove(2);
	cout<<" n = "<<my_map.size()<<endl;
	cout<<"remove key 4:\t"<<my_map.remove(4)<<endl;
	
	for (int i=0; i<n; i++)
		my_map[data[i]] = i;
	cout<<"foreach: "<<endl;
	for (int i=0; i<n; i++)
		cout<<my_map[data[i]]<<"\t";
	cout<<endl;

	return 0;
}