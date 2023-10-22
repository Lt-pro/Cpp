#include <iostream>

const double * f1(const double ar[], int n);
const double * f2(const double [], int);
const double * f3(const double *, int);

// 自动类型推断
// 函数指针的数组
// 函数指针数组的指针

int main()
{
	using namespace std;
	double av[3] = {1112.3, 1542.6, 2227.9};
	
	const double *(*p1)(const double *, int) = f1;
	auto p2 = f2;
	cout <<"Using pointers to functions: \n";
	cout <<"Address value\n";
	cout <<(*p1)(av, 1)<<": "<<*(*p1)(av, 2)<<endl;
	cout <<(*p2)(av, 1)<<": "<<*(*p2)(av, 2)<<endl;
	
	const double *(*pa[3])(const double *, int) = {f1, f2, f3};
	cout <<"Using a array of pointers to functions: \n";
	cout <<"Address value\n";
	for (int i=0; i<3;i++)
		cout <<(*pa[i])(av, i+1)<<": "<<*(*pa[i])(av, i+1)<<endl;
	
	const double *(*((*ap)[3]))(const double *, int) = &pa;
	cout <<"Using pointers to an array of pointers: \n";
	cout <<"Address value\n";
	for (int i=0;i<3;i++)
		cout <<(*(*ap)[i])(av, i+1)<<": "<<*(*(*ap)[i])(av, i+1)<<endl;
	
	
	return 0;
}

const double * f1(const double ar[], int n)
{
	return ar;
}
const double * f2(const double ar[], int n)
{
	return ar + 1;
}
const double * f3(const double ar[], int n)
{
	return ar + 2;
}