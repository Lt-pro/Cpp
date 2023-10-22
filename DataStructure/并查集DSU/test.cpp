#include <iostream>
#include "dsu.h"

using namespace std;


const int n = 10;
const int m = 5;
int main()
{
	int a2[n][2] = {
		{1, 5},
		{5, 7},
		{3, 4},
		{5, 8},
		{2, 6},
	};
	
	int q[3][2] = {
		{1, 7},
		{2, 4},
		{3, 7}
	};
	
	DSU s(n);
	s.aggreate(a2, m);
	int a, b;
	for (int i=0;i<3;i++)
	{
		a = q[i][0];
		b = q[i][1];
		if (s.search(a, b))
			cout <<"("<<a<<", "<<b<<") is equivalent"<<endl;
		else
			cout <<"("<<a<<", "<<b<<") isn't equivalent"<<endl;
	}
	
	return 0;
}