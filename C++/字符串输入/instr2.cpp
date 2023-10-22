#include <iostream>


int main()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];
	
	//cin.getline() 按行读取字符串，以换行符或读取到指定字符数终止，丢弃输入队列的换行符
	cout <<"Enter your name:\n";
	cin.getline(name, ArSize);
	cout <<"Enter your favorite dessert:\n";
	cin.getline(dessert, ArSize);
	cout <<"I have some delicious "<<dessert<<" for you, "<<name<<".\n";
	
	return 0;
}