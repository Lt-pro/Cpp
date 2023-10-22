#include <iostream>


int main()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];
	
	
	// cin 逐个单词读取字符串，以空格、制表和换行分隔
	cout <<"Enter your name:\n";
	cin >>name;
	cout <<"Enter your favorite dessert:\n";
	cin >>dessert;
	cout <<"I have some delicious "<<dessert<<" for you, "<<name<<".\n";
	
	return 0;
}