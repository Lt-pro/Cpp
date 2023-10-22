#include <iostream>

//计算高尔夫球的得分：读取5个输入得分，计算得分的平局值。如果有错误信息，清楚错误数据，并给出提示，直到5个数据全部读取完成。

const int MAX = 5;
int main()
{
	using namespace std;
	
	double golf[MAX];
	cout <<"Please enter the score of your golfs"<<endl;
	cout <<"You must your score for"<<MAX<<"rounds"<<endl;
	
	int i;
	for (i = 0; i < MAX; i++)
	{
		cout <<"Enter the score of golf #"<<i+1<<": ";
		while (!(cin>>golf[i]))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout <<"Error information is cleared, Enter the right socre: ";
		}
	}
	
	double total = 0;
	for (i=0;i<MAX;i++)
		total += golf[i];
	cout <<total/MAX<<" = the average score of golf"<<endl;
	
	return 0;
}