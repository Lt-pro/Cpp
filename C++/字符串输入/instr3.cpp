#include <iostream>


int main()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];
	
	//cin.get(str, size) ��.getline()������ͬ����������������еĻ��з�
	//cin.get() or cin.get(ch) ��ȡһ���ַ�����������. ����������������еĻ��з������ĳЩ�ж�
	//cin.get() ����һ��cin����
	cout <<"Enter your name:\n";
	cin.get(name, ArSize).get();
	cout <<"Enter your favorite dessert:\n";
	cin.getline(dessert, ArSize).get();
	cout <<"I have some delicious "<<dessert<<" for you, "<<name<<".\n";
	
	return 0;
}