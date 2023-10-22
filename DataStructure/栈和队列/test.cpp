#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;


int main()
{
	int e;
	
	cout <<"SqStack Test"<<endl;
	SqStack<int> stack1(10);
	cout <<"stack1 empty = "<<stack1.empty()<<endl;
	for (int i=0;i<=10;i++)
	{
		stack1.push(i);
		cout <<stack1.length()<<"\t";
	}
	cout <<endl<<"stack1 full = "<<stack1.full()<<endl;
	for (int i=0;i<=10;i++)
	{
		if (stack1.pop(e))
			cout <<e<<"\t";
	}
	cout <<endl;
	
	cout <<"LinkStack Test"<<endl;
	LinkStack<int> stack2;
	cout <<"stack2 empty = "<<stack2.empty()<<endl;
	for (int i=0;i<=20;i++)
	{
		stack2.push(i);
		cout <<stack2.length()<<"\t";
	}
	cout <<endl;
	for (int i=0;i<=10;i++)
	{
		stack2.pop(e);
		cout <<e<<"\t";
	}
	cout <<endl;
	
	cout <<"SqQueue Test"<<endl;
	SqQueue<int> q1(10);
	cout <<"q1 empty = "<<q1.empty()<<endl;
	for (int i=0;i<10;i++)
	{
		q1.push(i);
		cout <<q1.length()<<"\t";
	}
	cout <<endl<<"q1 full = "<<q1.full()<<endl;
	for (int i=0;i<10;i++)
	{
		q1.pop(e);
		cout <<e<<"\t";
	}
	cout <<endl;
	
	cout <<"LinkQueue Test"<<endl;
	LinkQueue<int> q2;
	cout <<"q2 empty = "<<q2.empty()<<endl;
	for (int i=0;i<20;i++)
	{
		q2.push(i%5);
		cout <<q2.length()<<"\t";
	}
	cout <<endl;
	for (int i=0;i<10;i++)
	{
		q2.pop(e);
		cout <<e<<"\t";
	}
	
	return 0;
}