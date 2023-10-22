#include <iostream>

// 计算一天鱼的重量，假设一天至多捕获5条鱼，当达到最大数目或者检测到'q'时停止输入，打印鱼的平均重量  
/**
输入错误可能引发的问题
1. 存储输入的变量保持不变
2. 不匹配的输入保留在输入队列
3. cin的错误标记被设置
4. 对cin方法的调用将返回false

错误处理
1. 清除标记位 cin.clear()
2. 清除错误输入 
*/

const int MAX = 5;
int main()
{
	using namespace std;
	
	double fish[MAX];
	int i = 0;
	
	cout << "Enter fish #1 or 'q' to terminate"<<endl;
	while (i < MAX && cin>>fish[i])
		cout <<"Enter fish #"<<++i+1<< "weight : "<<endl;
	
	double average = 0;
	for (int j=0;j<i;j++)
		average+=fish[j];
	if (i==0)
		cout <<"There is no fish"<<endl;
	else
		cout <<average/i<<" = the average weight of "<<i<<" fish"<<endl;
	
	return 0;
}