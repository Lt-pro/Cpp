#include <iostream>

using namespace std;

void swap(int &a, int &b);


int main(){
	
	int a = 10;
	int b = 20;
	
	cout <<"未调用前"<<"a = "<<a<<"b ="<<b<<endl;
	swap(a, b);
	cout <<"调用后"<<"a = "<<a<<"b = "<<b<<endl;
	
	return 0;
}

void swap(int &a, int &b){
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}