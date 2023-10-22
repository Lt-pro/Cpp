#include <iostream>


using namespace std;

/**
变量与const&static

const修饰的变量必须在声明时直接初始化。
static修饰的变量只能被定义一次，第二次即以后的变量声明将会被跳过，整个程序只有一个副本。
*/
class Cyrcle
{
	double r;
	public:
		static int count;
		static const double pi;		//这两个都只是声明
		Cyrcle(double r)
		{
			this->r = r;
			Cyrcle::count++;
		}
};
int Cyrcle::count = 0;
const double Cyrcle::pi = 3.1415926;


class MyClass
{
	public:
		const int a = 10;		//这个赋值是可以改变的，即这只相当于一个声明。
		MyClass(int n):a(n){};
};

double e1(double a)
{
	static double e = a;
	return e;
}
double e2(double a)
{
	static double e = a;
	e++;
	return e;
}

int main()
{
	const double pi = 3.1415926;	//常量必须在声明时初始化
	cout <<"pi = "<<pi<<endl;
	
	MyClass F(6);
	cout <<"F.a = "<<F.a<<" Address of F.a is"<<&F.a<<endl;
	
	
	cout <<"define a static variable e in e1"<<endl;
	cout <<e1(2.71)<<endl;
	cout <<e1(3.71)<<endl;
	cout <<e1(4.71)<<endl;
	
	cout <<"change number of e in e2"<<endl;
	cout <<e2(0)<<endl;
	cout <<e2(0)<<endl;				//虽然两个变量名称相同，但作用域不同，是两个独立的静态变量
	
	static const int universe = 42;//只有一个副本取值不可修改
	cout <<"universe = "<<universe<<endl;
	
	//double b;		//这是一个声明，不能多次声明同一变量
	double b = 1.41;//声明加初始化
	cout <<"b = "<<b<<endl;
	
	Cyrcle c1(1), c2(2);
	cout <<"Cyrcle::count = "<<Cyrcle::count<<endl;
	Cyrcle c3(3);
	cout <<"Cyrcle::count = "<<Cyrcle::count<<endl;
	cout <<"Cyrcle::pi = "<<Cyrcle::pi<<endl;
	
	return 0;
}