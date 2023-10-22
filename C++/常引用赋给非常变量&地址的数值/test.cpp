#include <iostream>


using namespace std;

const int a1 = 256;
const double b1 = 3.14;
const int &a = a1;
const double &b = b1;
int main()
{
	int c = a;
	double d = b;
	
	
	cout <<"const int a = 256;"<<endl;
	cout <<"const double b = 3.14;"<<endl;
	cout <<"const int &a = a1;"<<endl;
	cout <<"const double &b = b1;"<<endl;
	cout <<"int c = a; // c = "<<c<<endl;
	cout <<"double d = b; // d = "<<d<<endl;
	
	cout <<"sizeof address &a "<<sizeof(&a)<<endl;
	cout <<"number of address &a = "<<(int)(&a)<<endl;
	return 0;
}