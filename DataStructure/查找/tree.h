#ifndef _TREE_H_
#define _TREE_H_

// 查找：根据关键字查从数据集找匹配的数据元素。关键字具有唯一性
// 二叉排序树：若左子树非空，左子树结点关键字全部小于根节点；若右子树非空，右子树所有结点关键字均大于根结点；左右子树各是一颗二叉排序树
template <class T, class V>
class BST
{
	//二叉排序树结点
	class BSTNode
	{
		public:
			T key;		//类型T定义了比较运算符
			V value;
			BSTNode *left, *right;
			BSTNode(T k, V v):key(k), value(v), left(NULL), right(NULL){};
			~BSTNode()
			{
				left = NULL;
				right = NULL;
			}
	};
	
	BSTNode *bt;
	int n;
	bool _insert(BSTNode *&b, const T &key, const V &value)
	{
		if (b == NULL)
		{
			b = new BSTNode(key, value);
			n++;
			return true;
		}
		if (b->key == key)
			return false;
		else if (key < b->key)
			return _insert(b->left, key, value);
		else
			return _insert(b->right, key, value);
	}
	void _destory(BSTNode *&b)
	{
		if (b!=NULL)
		{
			_destory(b->left);
			_destory(b->right);
			delete b;
		}
	}
	BSTNode* _search(BSTNode *b, const T &key)
	{
		if (b==NULL || b->key==key)
			return b;
		if (key < b->key)
			return _search(b->left, key);
		else
			return _search(b->right, key);
	}	
	
	bool _erase(BSTNode *&b, const T &key)
	{
		if (b==NULL)
			return false;
		else if (key < b->key)
			return _erase(b->left, key);
		else if (key > b->key)
			return _erase(b->right, key);
		else
		{
			//b是引用参数，对应某个双亲结点的孩子结点
			BSTNode *q=NULL;
			if (b->right==NULL)
			{
				q = b;
				b = b->left;
				delete q;
			}
			else if (b->left==NULL)
			{
				q = b;
				b = b->right;
				delete q;
			}
			else
			{
				BSTNode *r=b->right;
				BSTNode *rp=NULL;	//r的父亲结点
				while (r->right!=NULL)
				{
					rp = r;
					r = r->right;
				}
				b->key = r->key;
				b->value = r->value;
				rp->right = r->left;
				delete r;
			}
			n--;
			return true;
		}
	}
	
	public:
		BST():bt(NULL),n(0){};
		BST(T keys[], V values[], int num)
		{
			for (int i=0;i<num;i++)
				_insert(this->bt, keys[i], values[i]);
		};
		~BST()
		{
			_destory(this->bt);
		};
		bool insert(const T &key, const V &value)
		{
			return _insert(this->bt, key, value);
		};
		bool search(const T &key, V &value)
		{
			BSTNode *p = _search(this->bt, key);
			if (p!=NULL)
			{
				value = p->value;
				return true;
			}
			else
				return false;
		};
		bool change(const T &key, const V &value)
		{
			BSTNode *p = _search(this->bt, key);
			if (p!=NULL)
			{
				p->value = value;
				return true;
			}
			else
				return false;
		};
		bool erase(const T &key)
		{
			return _erase(this->bt, key);
		};
		int length() const{return this->n;};
};


// 平衡二叉树
template <class T1, class T2>
class AVL{
	class AVLNode
	{
		public:
			T1 key;	//支持比较运算符
			T2 value;
			AVLNode *left, *right;
			
			AVLNode(const T1 &k, const T2 &v):key(k),value(v),left(NULL),right(NULL){};
	};
	int _height(const AVLNode *b);
	void _leftRotate(AVLNode *&b);
	void _rightRotate(AVLNode *&b);
	void _adjust(AVLNode *&b, const T1 &key); 
	void _destory(AVLNode *&b);
	bool _insert(AVLNode *&b, const T1 &key, const T2 &value);
	AVLNode* _search(AVLNode *b, const T1 &key);
	AVLNode* _erase(AVLNode *&b, AVLNode *&bp, const T1 &key);
	
	
	private:
		AVLNode *bt;
		int n;
		
	public:
		AVL():bt(NULL),n(0){};
		~AVL(){_destory(this->bt);};
		bool insert(const T1 &key, const T2 &value){return _insert(this->bt, key, value);};
		bool search(const T1 &key, T2 &value);
		bool change(const T1 &key, const T2 &value);
		bool erase(const T1 &key);
		int length() {return this->n;};
		int height(){return _height(this->bt);};
};
template <class T1, class T2>
int AVL<T1, T2>::_height(const AVL<T1, T2>::AVLNode *b)
{
	if (b==NULL)
		return 0;
	int m = _height(b->left);
	int n = _height(b->right);
	return m>n? m+1 : n+1;
}
template <class T1, class T2>
void AVL<T1, T2>::_leftRotate(AVL<T1, T2>::AVLNode *&b)
{
	//AVL<T1, T2>::AVLNode *p = b;
	AVLNode *p = b;
	b = b->right;
	p->right = b->left;
	b->left = p;
}
template <class T1, class T2>
void AVL<T1, T2>::_rightRotate(AVL<T1, T2>::AVLNode *&b)
{
	AVL<T1, T2>::AVLNode *p = b;
	b = b->left;
	p->left = b->right;
	b->right = p;
}
template <class T1, class T2>
void AVL<T1, T2>::_adjust(AVL<T1, T2>::AVLNode *&b, const T1 &key)
{
	// b:  根结点
	// bp: 待匹配结点
	if (b!=NULL)
	{
		std::cout<<"_adjust"<<std::endl;
		if (key < b->key)
			_adjust(b->left, key);
		else if (key > b->key)
			_adjust(b->right, key);
		
		//调整操作：从修改结点开始寻找失衡的最小子树
		if ( (_height(b->left)-_height(b->right)) > 1)
			if (b->left!=NULL && (_height(b->left->left)<_height(b->left->right)))
			{
				_leftRotate(b->left);	//LR
				_rightRotate(b);
			}
			else
				_rightRotate(b);		//LL
			
		if ((_height(b->left)-_height(b->right)) < -1)
			if (b->right!=NULL && (_height(b->right->left)>_height(b->right->right)))
			{
				_rightRotate(b->right);	//RL
				_leftRotate(b);
			}
			else
				_leftRotate(b);		//RR
	}
}
template <class T1, class T2>
bool AVL<T1, T2>::_insert(AVL<T1, T2>::AVLNode *&b, const T1 &key, const T2 &value)
{
	bool flag = true;
	if (b == NULL)
	{
		b = new AVL<T1, T2>::AVLNode(key, value);
		n++;
	}
	else if (key < b->key)
		flag = _insert(b->left, key, value);
	else if (key > b->key)
		flag = _insert(b->right, key, value);
	else
		flag = false;
	
	//调整操作：从修改结点开始寻找失衡的最小子树
	if ( (_height(b->left)-_height(b->right)) > 1)
		if (b->left!=NULL && (_height(b->left->left)<_height(b->left->right)))
		{
			_leftRotate(b->left);	//LR
			_rightRotate(b);
		}
		else
			_rightRotate(b);		//LL
		
	if ((_height(b->left)-_height(b->right)) < -1)
		if (b->right!=NULL && (_height(b->right->left)>_height(b->right->right)))
		{
			_rightRotate(b->right);	//RL
			_leftRotate(b);
		}
		else
			_leftRotate(b);			//RR
	
	return flag;
};
template <class T1, class T2>
void AVL<T1, T2>::_destory(AVL<T1, T2>::AVLNode *&b)
{
	if (b!=NULL)
	{
		_destory(b->left);
		_destory(b->right);
		delete b;
	}
}
template <class T1, class T2>
typename AVL<T1, T2>::AVLNode* AVL<T1, T2>::_search(AVL<T1, T2>::AVLNode *b, const T1 &key)
{
	if (b==NULL || b->key==key)
		return b;
	if (key < b->key)
		return _search(b->left, key);
	else
		return _search(b->right, key);
}
template <class T1, class T2>
typename AVL<T1, T2>::AVLNode* AVL<T1, T2>::_erase(AVL<T1, T2>::AVLNode *&b, AVL<T1, T2>::AVLNode *&bp, const T1 &key)
{
	if (b==NULL)
		return b;
	else if (key < b->key)
		return _erase(b->left, b, key);
	else if (key > b->key)
		return _erase(b->right, b, key);
	else
	{
		//b是引用参数，对应某个双亲结点的孩子结点
		AVLNode *q=NULL;
		if (b->right==NULL)
		{
			q = b;
			b = b->left;
			delete q;
			n--;
			return bp;
		}
		else if (b->left==NULL)
		{
			q = b;
			b = b->right;
			delete q;
			n--;
			return bp;
		}
		else
		{
			AVLNode *r=b->left;
			AVLNode *rp=NULL;	//r的父亲结点
			while (r->right!=NULL)
			{
				rp = r;
				r = r->right;
			}
			b->key = r->key;
			b->value = r->value;
			rp->right = r->left;
			delete r;
			n--;
			return rp;
		}
	}
}
template <class T1, class T2>
bool AVL<T1, T2>::search(const T1 &key, T2 &value)
{
	AVLNode *p = _search(this->bt, key);
	if (p!=NULL)
	{
		value = p->value;
		return true;
	}
	else
		return false;
};
template <class T1, class T2>
bool AVL<T1, T2>::change(const T1 &key, const T2 &value)
{
	AVLNode *p = _search(this->bt, key);
	if (p!=NULL)
	{
		p->value = value;
		return true;
	}
	else
		return false;
}
template <class T1, class T2>
bool AVL<T1, T2>::erase(const T1 &key) 
{
	AVLNode *p = _erase(this->bt, this->bt, key);
	if (p!=NULL)
	{
		_adjust(this->bt, p->key);
		return true;
	}
	else
		return false;
};

#endif