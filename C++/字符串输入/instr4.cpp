#include <iostream>

int main()
{
	//�����ַ����������
	using namespace std;
	cout <<"What year was your house built?\n";
	int year;
	cin >> year;	//cin��ȡ���ʱ�Ὣ���з�����������С�.getline()��������ʱ����Ϊ��һ�����У������ַ�������address����
	cout <<"What is its street address?\n";
	char address[80];
	cin.getline(address, 80);	//�û�û������address�Ļ���
	cout <<"Year built: "<<year<<endl;
	cout <<"Address: "<<address<<endl;
	cout <<"Done!\n";
	
	//������ʹ��cin��ȡboolֵ���ᷢ�������������
	//����ʹ������ת��Ϊbool
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
