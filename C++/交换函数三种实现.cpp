#include <iostream>

using namespace std;

void swap1(int &a, int &b);
void swap2(int &a, int &b);
void swap3(int &a, int &b);

int main(){
	int a = 10;
	int b = 20;
	
	cout <<"交换前"<<"a = "<<a<<"  b = "<<b<<endl;
	swap1(a, b);
	cout <<"swap1"<<"a = "<<a<<"  b = "<<b<<endl;
	swap2(a, b);
	cout <<"swap2"<<"a = "<<a<<"  b = "<<b<<endl;
	swap3(a, b);
	cout <<"swap3"<<"a = "<<a<<"  b = "<<b<<endl;
}

void swap1(int &a, int &b){
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void swap2(int &a, int &b){
	a = a + b;
	b = a - b;
	a = a - b;
}

void swap3(int &a, int &b){
	int tmp;
	tmp = a ^ b;
	a = tmp ^ a;
	b = tmp ^ b;
}