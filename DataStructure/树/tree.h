#include <iostream>

#define MaxSize 1024

/**
char binary tree
*/
template <class T> 
class BTNode
{
	public:
		T data;
		BTNode<T> *lchild;
		BTNode<T> *rchild;
		
		BTNode(){ lchild=nullptr; rchild=nullptr;};
};
class StrBTree
{
	BTNode<char> *root;
	void Destroy(BTNode<char> *b);
	BTNode<char>* Locate(BTNode<char> *b, char x);
	int Height(BTNode<char> *b);
	void Disp(BTNode<char> *b);
	
	public:
		StrBTree();
		StrBTree(char *str);
		~StrBTree()
		{
			this->Destroy(root);
		}
		BTNode<char>* locate(char x)
		{
			return this->Locate(root, x);
		}
		int height()
		{
			return this->Height(root);
		}
		void disp()
		{
			this->Disp(root);
		}
};
void StrBTree::Destroy(BTNode<char> *b)
{
	if(b!=nullptr)
	{
		Destroy(b->lchild);
		Destroy(b->rchild);
		delete b;
	}
}
BTNode<char>* StrBTree::Locate(BTNode<char> *b, char x)
{
	BTNode<char> *p=nullptr;
	if (b==nullptr)
		return nullptr;
	if (b->data==x)
		return b;
	else
	{
		p = StrBTree::Locate(b->lchild, x);
		if (p!=nullptr)
			return p;
		return StrBTree::Locate(b->rchild, x);
	}
}
int StrBTree::Height(BTNode<char> *b)
{
	int h1, h2;
	if (b==nullptr)
		return 0;
	h1 = StrBTree::Height(b->lchild);
	h2 = StrBTree::Height(b->rchild);
	return (h1>h2)? (h1+1) : (h2+1);
}
void StrBTree::Disp(BTNode<char> *b)
{
	using namespace std;
	if (b!=nullptr)
	{
		cout <<b->data;
		if (b->lchild!=nullptr || b->rchild!=nullptr)
		{
			cout <<'(';
			StrBTree::Disp(b->lchild);
			if (b->rchild!=nullptr)
				cout <<',';
			StrBTree::Disp(b->rchild);
			cout <<')';
		}
	}
}
StrBTree::StrBTree()
{
	root = new BTNode<char>;
}
StrBTree::StrBTree(char *str)
{
	root = nullptr;
	BTNode<char> *St[MaxSize], *p=nullptr;
	int top=-1, k, j=0;
	char ch = str[j];
	while (ch!='\0')
	{
		switch (ch)
		{
			case '(':
				top++;
				St[top] = p;
				k = 1;
				break;
			case ',':
				k = 2;
				break;
			case ')':
				top--;
				break;
			default:
				p = new BTNode<char>;
				p->data = ch;
				if (root==nullptr)
					root = p;
				else
				{
					switch (k)
					{
						case 1:
							St[top]->lchild = p;
							break;
						case 2:
							St[top]->rchild = p;
							break;
					}
				}
		}
		ch = str[++j];
	}
}



/**
字符串二叉链创建与销毁
*/
void create(BTNode<char> &*b, char *str)
{
	b = nullptr;
	BTNode<char> *St[MaxSize], *p=nullptr;
	int top=-1, k, j=0;
	char ch = str[j];
	while (ch!='\0')
	{
		switch (ch)
		{
			case '(':
				top++;
				St[top] = p;
				k = 1;
				break;
			case ',':
				k = 2;
				break;
			case ')':
				top--;
				break;
			default:
				p = new BTNode<char>;
				p->data = ch;
				if (b==nullptr)
					b = p;
				else
				{
					switch (k)
					{
						case 1:
							St[top]->lchild = p;
							break;
						case 2:
							St[top]->rchild = p;
							break;
					}
				}
		}
		ch = str[++j];
	}
}
void destroy(BTNode<char> *b)
{
	if(b!=nullptr)
	{
		destroy(b->lchild);
		destroy(b->rchild);
		delete b;
	}
}


/**
遍历算法： 以BTNode树结点，打印先序、中序、后序序列
递归实现： preorder1, inorder1, postorder1
非递归实现: preorder2, inorder2, postorder2

template <class T> 
class BTNode
{
	public:
		T data;
		BTNode<T> *lchild;
		BTNode<T> *rchild;
		
		BTNode(){ lchild=nullptr; rchild=nullptr;};
};
*/

using namespace std;


template <typename T>
void preorder1(BTNode<T> *b)
{
	if (b!=nullptr)
	{
		cout <<b->data<<" ";
		preorder1(b->lchild);
		preorder1(b->rchild);
	}
}
template <typename T>
void inorder1(BTNode<T> *b)
{
	if (b!=nullptr)
	{
		inorder1(b->lchild);
		cout <<b->data<<" ";
		inorder1(b->rchild);
	}
}
template <typename T>
void postorder1(BTNode<T> *b)
{
	if (b!=nullptr)
	{
		postorder1(b->lchild);
		postorder1(b->rchild);
		cout <<b->data<<" ";
	}
}
template <typename T> 
void preorder2(BTNode<T> *b)
{
	BTNode<T> *stack[MaxSize], *p=b;
	int top=-1;
	
	while (top!=-1 || p!=nullptr)
	{
		while (p!=nullptr)
		{
			stack[++top] = p;
			cout <<p->data<<" ";
			p = p->lchild;
		}
		if (top!=-1)
		{
			p = stack[top--];
			p = p->rchild;
		}
	}
}
template <typename T> 
void inorder2(BTNode<T> *b)
{
	BTNode<T> *stack[MaxSize], *p=b;
	int top=-1;
	
	while (top!=-1 || p!=nullptr)
	{
		while (p!=nullptr)
		{
			stack[++top] = p;
			p = p->lchild;
		}
		if (top!=-1)
		{
			p = stack[top--];
			cout <<p->data<<" ";
			p = p->rchild;
		}
	}
}
template <typename T>
void postorder2(BTNode<T> *b)
{
	BTNode<T> *stack[MaxSize], *p=b, *r=nullptr;
	int top=-1;
	bool flag;
	
	do
	{
		while (p!=nullptr)
		{
			stack[++top] = p;
			p = p->lchild;
		}
		flag = false;
		r = nullptr;
		while (top!=-1 && flag)
		{
			p = stack[top];
			if (p->rchild==r)
			{
				cout <<p->data<<" ";
				top--;
				r = p;
			}
			else
			{
				p = p->rchild;
				flag = false;
			}
		}
	}while(top!=-1);
}

























