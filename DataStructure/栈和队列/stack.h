#ifndef _STACK_H_
#define _STACK_H_


/*
顺序栈SqStack: 栈顶指针指向栈顶元素
LIFO
*/
template <class T>
class SqStack
{
	T *data;
	int Top;
	int len;
	int size;
	
	public:
		SqStack(int n);
		~SqStack();
		bool empty();
		bool full();
		int length();
		bool push(T e);
		bool pop(T &e);
		bool top(T &e);
};
template <class T>
SqStack<T>::SqStack(int n)
{
	data = new T[n];
	size = n;
	len = 0;
	Top = -1;
}
template <class T>
SqStack<T>::~SqStack()
{
	delete [] data;
}
template <class T>
bool SqStack<T>::empty()
{
	return Top==-1;
}
template <class T>
bool SqStack<T>::full()
{
	return Top==size-1;
}

template <class T>
int SqStack<T>::length()
{
	return len;
}
template <class T>
bool SqStack<T>::push(T e)
{
	if (Top==size-1)
		return false;
	Top++;
	data[Top] = e;
	len++;
	return true;
}
template <class T>
bool SqStack<T>::pop(T &e)
{
	if (Top==-1)
		return false;
	e = data[Top];
	Top--;
	len--;
	return true;
}
template <class T>
bool SqStack<T>::top(T &e)
{
	if (Top==-1)
		return false;
	e = data[Top];
	return true;
}



/*
链栈LinkStack：使用非循环单链表实现，表头指向栈顶元素
*/
template <class T>
class LinkStackNode
{
	//链栈节点
	public:
		T data;
		LinkStackNode<T> *next;
		LinkStackNode()
		{
			next = NULL;
		}
		~LinkStackNode(){};
};
template <class T>
class LinkStack
{
	int len;
	LinkStackNode<T> *H;
	
	public:
		LinkStack();
		~LinkStack();
		bool empty();
		int length();
		void push(T e);
		bool pop(T &e);
		bool top(T &e);
};
template <class T>
LinkStack<T>::LinkStack()
{
	len=0;
	H = new LinkStackNode<T>;
	H->next = NULL;
}
template <class T>
LinkStack<T>::~LinkStack()
{
	LinkStackNode<T> *pre=H, *p=H->next;
	while (p->next!=NULL)
	{
		delete pre;
		pre = p;
		p = p->next;
	}
	delete pre;
}
template <class T>
bool LinkStack<T>::empty()
{
	return H->next==NULL;
}
template <class T>
int LinkStack<T>::length()
{
	return len;
}
template <class T>
void LinkStack<T>::push(T e)
{
	LinkStackNode<T> *s = new LinkStackNode<T>;
	s->data = e;
	s->next = H->next;
	H->next = s;
	len++;
}
template <class T>
bool LinkStack<T>::pop(T &e)
{
	if (H->next==NULL)
		return false;
	LinkStackNode<T> *s=H->next;
	e = s->data;
	H->next = s->next;
	len--;
	delete s;
	return true;
}
template <class T>
bool LinkStack<T>::top(T &e)
{
	if (H->next==NULL)
		return false;
	e = H->next->data;
	return true;
}

#endif