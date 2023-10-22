#include <iostream>

using namespace std;

int main(){
	int n, delta;
	cout <<"请输入菱形的个数n(n>1)"<<endl;
	cin >>n;
	
	for (int i=0; i<2*n-1; i++){
		for (int j=0; j<2*n-1; j++){
			delta = i<n ? i : 2*n-2-i;
			if (j==n-1-delta || j==n-1+delta){
				cout <<"*";
			}
			else{
				cout <<" ";
			}
		}
		cout <<endl;
	}
}