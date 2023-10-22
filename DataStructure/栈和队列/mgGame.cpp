#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

#define MAXSIZE 100
int M = 8;
int N = 8;
int mg[10][10] = 
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};
int sx=1,sy=1;		//路径起点
int dx=M,dy=N;		//路径终点



typedef struct
{
	int x, y;
	int d;			//回溯法迷宫方位,广度优先搜索前驱节点下标
} Box;

bool mgPath1(int mg[10][10], int sx, int sy, int dx, int dy);
bool mgPath2(int mg[10][10], int sx, int sy, int dx, int dy);


int main()
{
	/*
	cout <<"回溯法"<<endl;
	if (!mgPath1(mg, sx,sy,dx,dy))
		cout <<"该迷宫问题没有解"<<endl;
	*/
	cout <<"广度优先搜索"<<endl;
	if (!mgPath2(mg, sx,sy,dx,dy))
		cout <<"该迷宫问题没有解"<<endl;
	return 0;
}

bool mgPath1(int mg[10][10], int sx, int sy, int dx, int dy)
{
	//回溯法
	Box path[MAXSIZE];
	Box e={sx, sy, -1}, next={0,0,-1};
	SqStack<Box> mgstack(MAXSIZE);
	mgstack.push(e);
	mg[sx][sy] = -1;
	while (!mgstack.empty())
	{
		mgstack.pop(e);
		if (e.x==dx && e.y==dx)
		{
			cout <<"找到一条迷宫路径："<<endl;
			int k=0, cnt=1;
			path[k++] = e;
			while (!mgstack.empty())
			{
				mgstack.pop(e);
				path[k++] = e;
			}
			while (k>=1)
			{
				k--;
				cout <<"("<<path[k].x<<","<<path[k].y<<")\t";
				if (cnt%5==0)
					cout <<endl;
				cnt++;
			}
			cout <<endl;
			return true;
		}
		while (e.d<3)
		{
			e.d++;
			switch (e.d)
			{
				case 0:
					next.x = e.x+1;
					next.y = e.y;
					break;
				case 1:
					next.x = e.x;
					next.y = e.y+1;
					break;
				case 2:
					next.x = e.x-1;
					next.y = e.y;
					break;
				case 3:
					next.x = e.x;
					next.y = e.y-1;
					break;
			}
			if (mg[next.x][next.y]==0)
			{
				mgstack.push(e);		//push实质是原本元素的一个副本
				mgstack.push(next);
				mg[next.x][next.y] = -1;
				break;
			}
		}
	}
	return false;
}

bool mgPath2(int mg[10][10], int sx, int sy, int dx, int dy)
{
	//广度优先搜索
	//非循环队允许访问更改队内元素,访问指针
	int d=-1, cnt=0;
	Box e={sx, sy, -1}, next={0,0,-1};
	SqQueue<Box> mgqueue(MAXSIZE, false);
	mgqueue.push(e);
	mg[sx][sy] = -1;
	while (!mgqueue.empty())
	{
		mgqueue.pop(e);
		if (e.x==dx && e.y==dy)
		{
			//输出迷宫路径
			cout <<"找到一条迷宫路径："<<endl;
			int k=mgqueue.getFront(),j;
			do
			{
				j = k;
				mgqueue.get(k, e);
				k = e.d;
				e.d = -1;
				mgqueue.set(j,e);
			}while(k!=0);
			k = 0;
			cnt = 1;
			while (k<MAXSIZE)
			{
				mgqueue.get(k, e);
				if (e.d==-1)
				{
					cout <<"("<<e.x<<","<<e.y<<")\t";
					if (cnt%5==0)
						cout <<endl;
					cnt++;
				}
				k++;
			}
			return true;
		}
		d=-1;
		while (d<3)
		{
			d++;
			switch (d)
			{
				case 0:
					next.x = e.x+1;
					next.y = e.y;
					break;
				case 1:
					next.x = e.x;
					next.y = e.y+1;
					break;
				case 2:
					next.x = e.x-1;
					next.y = e.y;
					break;
				case 3:
					next.x = e.x;
					next.y = e.y-1;
					break;
			}
			if (mg[next.x][next.y]==0)
			{
				next.d = mgqueue.getFront();
				mgqueue.push(next);
				mg[next.x][next.y] = -1;
				cnt++;
			}
		}
	}
	return false;
}