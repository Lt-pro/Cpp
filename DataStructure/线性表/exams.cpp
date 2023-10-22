#include <iostream>
#include "linearList.h"

using namespace std;

template <typename T>
void delnodel1(SqList<T> &L, T x)
{
	//ɾ��˳�����ֵΪx��Ԫ��
	//���֣�kΪ������x��Ԫ����Ŀ��0~k-1Ϊ������x��Ԫ�����䣬i~lengthΪ�����������䡣
	T e;
	int k=0;
	for (int i=0;i<L.length();i++)
	{
		L.get(i+1, e);
		if (e!=x)
		{
			L.set(k+1, e);
			k++;
		}
	}
	for (int i=L.length();i>k;i--)
	{
		L.erase(i, e);
	}
}

template <typename T>
void delnodel2(SqList<T> &L, T x)
{
	//ɾ��˳�����ֵΪx��Ԫ��
	//���֣�kΪ����x��Ԫ����Ŀ��0~i-k-1Ϊ������x��Ԫ�����䣬i~lengthΪ�����������䡣
	T e;
	int k=0, len=L.length();
	for (int i=0;i<len;i++)
	{
		L.get(i+1, e);
		if (e==x)
			k++;
		else
			L.set(i+1-k, e);
		
	}
	for (int i=len;i>len-k;i--)
		L.erase(i, e);
}


template <typename T>
void partition1(SqList<T> &L)
{
	//����һ��˳����Ե�һ��Ԫ��Ϊ��׼��������С�ڻ��������Ԫ�ط�������ǰ�棬��������Ԫ�ط������ĺ���
	//˫ָ��
	int i=1,j=L.length();
	T pivot, tmp, e;
	L.get(1, pivot);
	while (i<j)
	{
		L.get(j, e);
		while (i<j && e>pivot)
		{
			j--;
			L.get(j, e);
		}
		L.get(i, e);
		while (i<j && e<=pivot)
		{
			i++;
			L.get(i, e);
		}
		if (i<j)
		{
			L.get(i, tmp);
			L.get(j, e);
			L.set(i, e);
			L.set(j, tmp);
		}
	}
	L.get(1, tmp);
	L.get(i, e);
	L.set(1, e);
	L.set(i, tmp);
}

template <typename T>
void partition2(SqList<T> &L)
{
	//����һ��˳����Ե�һ��Ԫ��Ϊ��׼��������С�ڻ��������Ԫ�ط�������ǰ�棬��������Ԫ�ط������ĺ���
	//˫ָ��,����һ��հ׿ռ�
	int i=1, j=L.length();
	T pivot, e;
	L.get(1, pivot);
	while (i<j)
	{
		L.get(j, e);
		while (i<j && e>pivot)
		{
			j--;
			L.get(j, e);
		}
		L.set(i, e);
		L.get(i, e);
		while (i<j && e<=pivot)
		{
			i++;
			L.get(i, e);
		}
		L.set(j, e);
	}
	L.set(i, pivot);
}

template <typename T>
void move1(SqList<T> &L)
{
	//���������ֵ�ż��ǰ��
	//˫ָ�룬���仮�֣��������䡢��ɨ�����䡢ż������
	int i=1, j=L.length();
	T e, tmp;
	while (i<j)
	{
		L.get(j, e);
		while (i<j && e%2==0)
		{
			j--;
			L.get(j, e);
		}
		L.get(i, e);
		while (i<j && e%2==1)
		{
			i++;
			L.get(i, e);
		}
		if (i<j)
		{
			L.get(i, tmp);
			L.get(j, e);
			L.set(i, e);
			L.set(j, tmp);
		}
	}
}

template <typename T>
void move2(SqList<T> &L)
{
	//���������ֵ�ż��ǰ��
	//˫ָ�룬���仮��:�������䡢ż�����䡢��ɨ������
	int i=0,j;
	T e, tmp;
	for (j=1;j<=L.length();j++)
	{
		L.get(j, e);
		if (e%2==1)
		{
			i++;
			if (i!=j)
			{
				L.get(i, tmp);
				L.set(i, e);
				L.set(j, tmp);
			}
		}
	}
}

int main()
{
	//ɾ��˳�����ֵΪx��Ԫ��
	int a[10] = {1,2,3,4,5,1,2,3,4,5};
	SqList<int> L1(20), L2(20);
	
	for (int i=1;i<=10;i++)
	{
		L1.insert(i, a[i-1]);
		L2.insert(i, a[i-1]);
	}
	
	cout <<"L1 delete 1"<<endl;
	delnodel1(L1, 1);
	L1.disp();
	cout <<"L2 delete 2"<<endl;
	cout <<L2.length()<<endl;
	delnodel2(L2, 2);
	cout <<L2.length()<<endl;
	L2.disp();
	
	
	//����һ��˳����Ե�һ��Ԫ��Ϊ��׼��������С�ڻ��������Ԫ�ط�������ǰ�棬��������Ԫ�ط������ĺ���
	int b[10] = {4, 10, 9, 8, 7, 6, 5, 3, 2, 1};
	SqList<int> L3(20), L4(20);
	
	for (int i=1;i<=10;i++)
	{
		L3.insert(i, b[i-1]);
		L4.insert(i, b[i-1]);
	}
	
	cout <<"sort"<<endl;
	partition1(L3);
	partition2(L4);
	L3.disp();
	L4.disp();
	
	//���������ֵ�ż��ǰ��
	cout <<"even and odd"<<endl;
	move1(L3);
	move2(L4);
	L3.disp();
	L4.disp();
}