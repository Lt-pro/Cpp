#include<iostream>

// 散列表实现
// 无符号整型关键字
// 除留余数法加线性探测法
// 除留余数法加拉链法


// 除留余数法加线性探测法
#define NULLKEY -1
#define DELKEY -2

template <class T>
class map1 {
private:
	class Node {
	public:
		unsigned int key;
		int count;
		T value;
		Node(unsigned int k=NULLKEY, int c=0):key(k), count(c){}
		Node(unsigned int k, int c, T v):key(k), count(c), value(v){}
	};

	Node *num;
	int n;
	int m;
	int p;
public:
	map1(int m, int p);
	//map1(const map1& obj);
	~map1() {delete [] num;};
	T& operator[](unsigned int key);
	//map1& operator=(const map1& obj);
	bool remove(unsigned int key);
	int size() {return n;}
};
template <class T>
map1<T>::map1(int m, int p) {
	this->num = new Node[m];
	this->n = 0;
	this->m = m;
	this->p = p;
}
template <class T>
T& map1<T>::operator[](unsigned int key) {
	int add = key % p;
	int i = 1;
	// m>n, 否则可能无法终止
	while (num[add].key!=NULLKEY && num[add].key!=key)
		add = (add + 1)%m;
	if (num[add].key!=key) {
		add = key % p;
		while (num[add].key!=NULLKEY && num[add].key!=DELKEY){
			i++;
			add = (add + 1) % m;
		} 
		num[add] = Node(key, i);
		n++;
	}
	return num[add].value;
}
template <class T>
bool map1<T>::remove(unsigned int key) {
	int add = key%p;
	while (num[add].key!=NULLKEY&&num[add].key!=key)
		add = (add + 1) % m;
	if (num[add].key==key) {
		num[add].key = DELKEY;
		n--;
		return true;
	}
	return false;
}


// 除留余数法加拉链法
// 装载因子可以大于或等于1
template <class T>
class map2 {
private:
	class Node {
	public:
		unsigned int key;
		T value;
		Node* next;
		Node(unsigned int k=NULLKEY):key(k){next=nullptr;}
		Node(unsigned int k, const T& v):key(k), value(v), next(nullptr){}
	};
	
	Node **num;
	int n;
	int m;
	int p;
public:
	map2(int m, int p);
	//map2(const map2& obj);
	~map2();
	//map2& operator=(const map2& obj);
	T& operator[](unsigned int key);
	bool remove(unsigned int key);
	int size(){return n;}
};
// 参数传递
// 基本类型：值传递
// 非基本类型：常引用>常指针>引用>指针>值传递
template <class T>
map2<T>::map2(int m, int p) {
	this->num = new Node*[m];
	for (int i=0; i<m; i++)
		this->num[i] = nullptr;
	this->n = 0;
	this->m = m;
	this->p = p;
}
template <class T>
map2<T>::~map2<T>() {
	for (int i=0; i<m; i++)
		delete num[i];
	delete [] num;
}
template <class T>
T& map2<T>::operator[](unsigned int key) {
	int add = key%p;
	//首结点为空
	if (num[add]==nullptr) {
		num[add] = new Node(key);
		n++;
		return num[add]->value;
	}
	//首结点非空
	Node *p = num[add], *pre=nullptr;
	while (p!=nullptr && p->key!=key) {
		pre = p;
		p = p->next;
	}
	if (p==nullptr) {
		pre->next = p =new Node(key);
		n++;
	}
	return p->value;
}
template <class T>
bool map2<T>::remove(unsigned int key) {
	int add = key%p;
	Node *p = num[add], *pre = nullptr;
	while (p!=nullptr && p->key!=key) {
		pre = p;
		p = p->next;
	}
	if (p!=nullptr) {
		n--;
		if (pre==nullptr)
			num[add] = nullptr;
		else 
			pre->next = p->next;
		delete p;
		return true;
	}
	return false;
}