#ifndef _QUEUE_H_
#define _QUEUE_H_


/*
顺序队SqQueue:队头指针指向队头前一个元素，队尾指针指向队尾元素
FIFO
*/
template <class T>
class SqQueue
{
	T *data;
	int front, rear;
	int len;
	int size;
	bool cycle;
	
	public:
		SqQueue(int n, bool cycle=true);
		~SqQueue();
		bool empty();
		bool full();
		int length();
		bool push(T e);
		bool pop(T &e);
		bool get(int i, T &e);
		bool set(int i, T e);
		int getFront();
};
template <class T>
SqQueue<T>::SqQueue(int n, bool cycle)
{
	this->cycle = cycle;
	this->size = n;
	this->len = 0;
	this->front = cycle ? 0:-1;
	this->rear = cycle ? 0:-1;
	this->data = new T[n];
}
template <class T>
SqQueue<T>::~SqQueue()
{
	delete [] data;
}
template <class T>
bool SqQueue<T>::empty()
{
	return len==0;
}
template <class T>
bool SqQueue<T>::full()
{
	if (cycle)
		return len==size;
	else
		return rear==size-1;
}
template <class T>
int SqQueue<T>::length()
{
	return len;
}
template <class T>
bool SqQueue<T>::push(T e)
{
	if (this->full())
		return false;
	if (cycle)
	{
		rear = (front+len)%size;
		rear = (rear+1)%size;
	}else
		rear++;
	data[rear] = e;
	len++;
	return true;
}
template <class T>
bool SqQueue<T>::pop(T &e)
{
	if (len==0)
		return false;
	if (cycle)
		front = (front+1)%size;
	else
		front++;
	e = data[front];
	len--;
	return true;
}
template <class T>
bool SqQueue<T>::get(int i, T &e)
{
	if (cycle || i<0 || i>=size)
		return false;
	e = data[i];
	return true;
}
template <class T>
bool SqQueue<T>::set(int i, T e)
{
	if (cycle || i<0 || i>=size)
		return false;
	data[i] = e;
	return true;
}
template <class T>
int SqQueue<T>::getFront()
{
	return front;
}


/*
链队LinkQueue
非循环单链表实现：一个表头元素、一个表尾元素分别指向队头和队尾
也可使用循环单链表实现，只需一个尾节点
*/

template <class T>
class LinkQueueNode
{
	//链队节点
	public:
		T data;
		LinkQueueNode<T> *next;
		LinkQueueNode()
		{
			next=NULL;
		}
		~LinkQueueNode(){}
};
template <class T>
class LinkQueue
{
	int len;
	LinkQueueNode<T> *front;
	LinkQueueNode<T> *rear;
	
	public:
		LinkQueue();
		~LinkQueue();
		bool empty();
		int length();
		void push(T e);
		bool pop(T &e);		
};
template <class T>
LinkQueue<T>::LinkQueue()
{
	len=0;
	front = new LinkQueueNode<T>;
	front->next = NULL;
	rear = new LinkQueueNode<T>;
	rear->next = NULL;
}
template <class T>
LinkQueue<T>::~LinkQueue()
{
	LinkQueueNode<T> *pre=front, *p=front->next;
	while (p!=NULL)
	{
		delete pre;
		pre = p;
		p = p->next;
	}
	delete pre;
	delete rear;
}
template <class T>
bool LinkQueue<T>::empty()
{
	return len==0;
}
template <class T>
int LinkQueue<T>::length()
{
	return len;
}
template <class T>
void LinkQueue<T>::push(T e)
{
	LinkQueueNode<T> *s = new LinkQueueNode<T>;
	s->data = e;
	s->next = NULL;
	if (len==0)
	{
		front->next = s;
		rear->next = s;
	}else
	{
		rear->next->next = s;
		rear->next = s;
	}
	len++;
}
template <class T>
bool LinkQueue<T>::pop(T &e)
{
	LinkQueueNode<T> *s=front->next;
	if (s==NULL)
		return false;
	len--;
	e = s->data;
	if (front->next==rear->next)
		front->next=rear->next=NULL;
	else
	{
		front->next = front->next->next;
	}
	delete s;
	return true;
}
#endif

