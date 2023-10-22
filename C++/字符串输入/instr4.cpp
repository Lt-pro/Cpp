#include <iostream>

int main()
{
	//数字字符串混合输入
	using namespace std;
	cout <<"What year was your house built?\n";
	int year;
	cin >> year;	//cin读取年份时会将换行符留在输入队列。.getline()看到换行时会认为是一个空行，将空字符串赋给address数组
	cout <<"What is its street address?\n";
	char address[80];
	cin.getline(address, 80);	//用户没有输入address的机会
	cout <<"Year built: "<<year<<endl;
	cout <<"Address: "<<address<<endl;
	cout <<"Done!\n";
	
	//不建议使用cin读取bool值，会发生难以理解的情况
	//可以使用数字转换为bool
	bool a, b;
	int c;
	//cout <<"Enter true or false"<<endl;
	//cin >>a;
	//cout <<"bool a = "<<a<<endl;
	cout <<"Enter first digital: ";
	cin >>c;
	a = (bool)c;
	cout <<"Enter second digital: ";
	cin >>c;
	b = (bool)c;
	cout <<" a = "<<a<<" b = "<<b<<endl;
	
	return 0;
}
