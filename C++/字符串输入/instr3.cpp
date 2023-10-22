#include <iostream>


int main()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];
	
	//cin.get(str, size) 与.getline()作用相同，但不丢弃输入队列的换行符
	//cin.get() or cin.get(ch) 读取一个字符，包括换行. 可用来消除输入队列的换行符或进行某些判定
	//cin.get() 返回一个cin对象
	cout <<"Enter your name:\n";
	cin.get(name, ArSize).get();
	cout <<"Enter your favorite dessert:\n";
	cin.getline(dessert, ArSize).get();
	cout <<"I have some delicious "<<dessert<<" for you, "<<name<<".\n";
	
	return 0;
}