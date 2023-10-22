// ���Ա�{a_i, 1<=i<=n}
#ifndef _LINEARLIST_H_
#define _LINEARLIST_H_

#endif


#define MaxSize 50
typedef int ElemType;

using namespace std;



#ifndef _SQLISTS_

#define _SQLISTS_
//˳���ṹ��ʵ��
typedef struct {
	ElemType data[MaxSize];
	int length;
} SqListS;

#endif


void CreateList(SqListS *&L, ElemType a[], int n);
void InitList(SqListS *&L);
void DestoryList(SqListS *&L);
bool ListEmpty(SqListS *L);
int ListLength(SqListS *L);
void DispList(SqListS *L);
bool GetElem(SqListS *L, int i, ElemType &e);
int LocateElem(SqListS *L, ElemType e);
bool ListInsert(SqListS *&L, int i, ElemType e);
bool ListDelete(SqListS *&L, int i, ElemType &e);


#ifndef _SQLIST_

#define _SQLIST_
//˳���ģ��ʵ��
//ģ���ඨ����ʵ�ֲ��ܷ��룬����ͬʱ����.h��.cpp�ļ�
template <class T>
class SqList{
	T *data;
	int len;
	int size;
	
	public:
		SqList(int n);
		SqList(const SqList &L);
		~SqList();
		bool empty();
		int length();
		void disp();
		bool get(int i, T &e);
		bool set(int i, T e);
		int locate(T e);
		bool insert(int i, T e);
		bool erase(int i, T &e);
};

#endif

template <class T>
SqList<T>::SqList(int n){
	data = new T[n];
	len = 0;
	size = n;
}
template <class T>
SqList<T>::SqList(const SqList &L){
	data = new T[(const int) L.size];
	len = 0;
	size = L.size;
	
	for (int i=0;i<L.length(); i++){
		L.get(i+1, data[i]);
	}
}
template <class T>
SqList<T>::~SqList(){
	delete [] data;
}
template <class T>
bool SqList<T>::empty(){
	return len==0;
}
template <class T>
int SqList<T>::length(){
	return len;
}
template <class T>
void SqList<T>::disp(){
	for(int i=0;i<len;i++){
		cout<<i+1<<'\t'<<data[i]<<endl;
	}
}
template <class T>
bool SqList<T>::get(int i, T &e){
	if (i<1 || i>len){
		return false;
	}
	e = data[--i];
	return true;
}
template <class T>
bool SqList<T>::set(int i, T e){
	if (i<1 || i>len){
		return false;
	}
	data[--i] = e;
	return true;
}
template <class T>
int SqList<T>::locate(T e){
	int i=0;
	while (i<len && data[i]!=e){
		i++;
	}
	if (i>=len){
		return 0;
	}
	else{
		return i+1;
	}
}
template <class T>
bool SqList<T>::insert(int i, T e){
	if (i<1 || i>len+1 || i>size){
		return false;
	}
	i--;
	for (int j=len;j>i;j--){
		data[j] = data[j-1];
	}
	data[i] = e;
	len++;
	return true;
	
}
template <class T>
bool SqList<T>::erase(int i, T &e){
	if (i<1 || i>len){
		return false;
	}
	i--;
	for (int j=i;j<len-1;j++){
		data[j] = data[j+1];
	}
	len--;
	return true;
}


/*
������
���壺ÿ���ڵ�ֻ��һ������Ԫ�غ�ָ����Ԫ�ص�ָ��
��ͷ�����ڱ�ʶ����
��ͷ�ĺô���1�����ڴ���ͷ�ڵ�Ĳ���ɾ���Ȳ�����2��ͳһ�˿ձ�ͷǿձ�
*/

template <class T>
class LinkNode
{
	T data;
	LinkNode<T> *next;
	
	public:
		LinkNode();
		LinkNode(T a[], int n, bool R=true);
		~LinkNode();
		bool empty();
		int length();
		bool get(int i, T &e);
		int locate(T e);
		bool insert(int i, T e);
		bool erase(int i, T &e);
};

template <class T>
LinkNode<T>::LinkNode()
{
	next = NULL;
}
template <class T>
LinkNode<T>::LinkNode(T a[], int n, bool R)
{
	this->next = NULL;
	LinkNode<T> *r = this, *s=NULL;
	if (R)
	{
		//β�巨
		//����Ԫ��˳��������Ԫ��˳����ͬ
		//O(n)
		for (int i=0;i<n;i++)
		{
			s = new LinkNode;
			s->next = NULL;
			s->data = a[i];
			r->next = s;
			r = s;
		}
	}else
	{
		//ͷ�巨
		//����Ԫ��˳��������Ԫ��˳���෴
		//O(n)
		for (int i=0;i<n;i++)
		{
			s = new LinkNode;
			s->data = a[i];
			s->next = this->next;
			this->next = s;
		}
	}
}
template <class T>
LinkNode<T>::~LinkNode()
{
	//����ɾ���Ľڵ�ָ��ĵ�ַ��Ϊ�գ�ɾ����ǰ�ڵ�
	//ͷ�ڵ㽻��ϵͳ�����ͷ���Դ
	LinkNode<T> *pre=this->next, *p=NULL;
	while(pre!=NULL)
	{
		p = pre->next;
		pre->next = NULL;
		delete pre;
		pre = p;
	}
	//delete this;//������������������ô��
	//cout <<this<<endl;
}
template <class T>
bool LinkNode<T>::empty()
{
	return next==NULL;
}
template <class T>
int LinkNode<T>::length()
{
	LinkNode<T> *p = this->next;
	int i = 0;
	while (p!=NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}
template <class T>
bool LinkNode<T>::get(int i, T &e)
{
	int j=0;
	LinkNode<T> *p=this;
	if (i<=0)
		return false;
	while (j<i && p!=NULL)
	{
		j++;
		p = p->next;
	}
	if (p==NULL)
	{
		return false;
	}else
	{
		e = p->data;
		return true;
	}
}
template <class T>
int LinkNode<T>::locate(T e)
{
	int j=1;
	LinkNode<T> *p = this->next;
	while (p!=NULL && p->data!=e)
	{
		j++;
		p = p->next;
	}
	if (p==NULL)
	{
		return 0;
	}else
	{
		return j;
	}
}
template <class T>
bool LinkNode<T>::insert(int i, T e)
{
	int j=0;
	LinkNode<T> *p = this, *s;
	if (i<=0)
		return false;
	
	while (j<i-1 && p!=NULL)
	{
		j++;
		p = p->next;
	}
	if (p==NULL)
	{
		return false;
	}else
	{
		s = new LinkNode<T>;
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}
template <class T>
bool LinkNode<T>::erase(int i, T &e)
{
	int j=0;
	LinkNode<T> *p = this, *s;
	if (i<=0)
		return false;
	while (j<i-1 && p!=NULL)
	{
		j++;
		p = p->next;
	}
	s = p->next;
	p->next = s->next;
	s->next = NULL;
	e = s->data;
	delete s;
	return true;
}



/*
˫����
���壺ÿ���ڵ���һ������Ԫ�ء�ָ��ǰ���ڵ��ָ���ָ���̽ڵ��ָ��
*/

//�ڵ�Ԫ��
template <class T>
class DLinkNode
{
	public:
		//�ڵ�Ĵ���ɾ�����޸Ľ���������ɣ�ͷ�ڵ�����Ϊ˽�����ԣ�ͬ���ɱ�֤���ɼ�
		T data;
		DLinkNode *prior;
		DLinkNode *next;
	
	public:
		DLinkNode()
		{
			this->prior = NULL;
			this->next = NULL;
		}
		~DLinkNode()
		{
			this->prior = NULL;
			this->next = NULL;
		}
};
//����ģ��
template <class T>
class DList
{
	DLinkNode<T> *H;	//ͷ�ڵ�
	int len;
	
	public:
		DList();
		DList(const DList &L);
		DList(T a[], int n, bool R=true);
		~DList();
		void disp();
		bool empty();
		int length();
		bool get(int i, T &e);
		int locate(T e);
		bool insert(int i, T e);
		bool erase(int i, T &e);
};
template <class T>
DList<T>::DList()
{
	H = new DLinkNode<T>;
	H->prior = NULL;
	H->next = NULL;
	len = 0;
}
template <class T>
DList<T>::DList(const DList &L)
{
	this->H = new DLinkNode<T>;
	this->H->prior = NULL;
	this->H->next = NULL;
	this->len = 0;
	
	DLinkNode<T> *p=L->H->next, *s, *r;
	r = this->H;
	while (p!=NULL)
	{
		s = new DLinkNode<T>;
		s->data = p->data;
		s->prior = r;
		r->next = s;
		r = s;
		this->len++;
	}
	r->next = NULL;
}
template <class T>
DList<T>::DList(T a[], int n, bool R)
{
	this->H = new DLinkNode<T>;
	this->H->prior = NULL;
	this->H->next = NULL;
	this->len = 0;
	
	DLinkNode<T> *s, *r;
	r = this->H;
	if (R)
	{
		//β�巨
		for (int i=0;i<n;i++)
		{
			s = new DLinkNode<T>;
			s->data = a[i];
			s->prior = r;
			r->next = s;
			r = s;
			this->len++;
		}
		r->next = NULL;
	}else
	{
		//ͷ�巨
		for (int i=0;i<n;i++)
		{
			s = new DLinkNode<T>;
			s->data = a[i];
			s->prior = this->H;
			if (this->H->next!=NULL)
				this->H->next->prior = s;
			s->next = this->H->next;
			this->H->next = s;
			this->len++;
		}
	}
}
template <class T>
DList<T>::~DList()
{
	DLinkNode<T> *p=this->H,*q=this->H->next;
	while (q!=NULL)
	{
		delete p;
		p = q;
		q = q->next;
	}
	delete p;
}
template <class T>
void DList<T>::disp()
{
	DLinkNode<T> *p=this->H->next;
	int i=1;
	cout <<"List length: "<<len<<endl;
	while(p!=NULL)
	{
		cout <<i<<"\t\t"<<p->data<<endl;
		p = p->next;
		i++;
	}
}
template <class T>
bool DList<T>::empty()
{
	return H->next == NULL;
}
template <class T>
int DList<T>::length()
{
	return len;
}
template <class T>
bool DList<T>::get(int i, T &e)
{
	int j=1;
	DLinkNode<T> *p=this->H->next;
	if (i<=0) 
		return false;
	while (j<i && p!=NULL)
	{
		j++;
		p = p->next;
	}
	if (p==NULL)
		return false;
	else
	{
		e = p->data;
		return j;
	}
}
template <class T>
int DList<T>::locate(T e)
{
	int j=1;
	DLinkNode<T> *p=this->H->next;
	while (p!=NULL && p->data!=e)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return 0;
	else
		return j;
}
template <class T>
bool DList<T>::insert(int i, T e)
{
	int j=0;
	DLinkNode<T> *p=this->H, *s;
	if (i<=0) 
		return false;
	while (j<i-1 && p!=NULL)
	{
		j++;
		p = p->next;
	}
	if (p==NULL)
		return false;
	else
	{
		s = new DLinkNode<T>;
		s->data = e;
		if (p->next!=NULL)
			p->next->prior = s;
		s->next = p->next;
		s->prior = p;
		p->next = s;
		this->len++;
		return true;
	}
}
template <class T>
bool DList<T>::erase(int i, T &e)
{
	int j=0;
	DLinkNode<T> *p=this->H, *q;
	if (i<=0)
		return false;
	while (j<i-1 && p!=NULL)
	{
		j++;
		p = p->next;
	}
	if (p==NULL)
		return false;
	else
	{
		q = p->next;
		if (q==NULL)
			return false;
		else
		{
			p->next = q->next;
			delete q;
			if (p->next!=NULL)
				p->next->prior = p;
			this->len--;
			return true;
		}
	}
}





