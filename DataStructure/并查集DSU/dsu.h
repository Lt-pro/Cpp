
struct DSUNode
{
	int idx;
	int rank;
	int parent;
};
class DSU
{
	DSUNode *p;
	int _find(DSUNode a[], int x);
	
	public:
		DSU(int n);
		~DSU();
		void aggreate(int a2[][2], int m);
		void aggreate(int a, int b);
		bool search(int a, int b);
};
DSU::DSU(int n)
{
	p = new DSUNode[n+1];
	for (int i=1;i<=n;i++)
	{
		p[i].idx = i;
		p[i].rank = 0;
		p[i].parent = i;
	}
}
DSU::~DSU()
{
	delete [] p;
}
int DSU::_find(DSUNode a[], int x)
{
	//递归方法不推荐在内部使用成员变量
	if (x!=a[x].parent)
		return DSU::_find(a, a[x].parent);
	else
		return x;
}
void DSU::aggreate(int a, int b)
{
	a = this->_find(this->p, a);
	b = this->_find(this->p, b);
	if (this->p[a].rank > this->p[b].rank)
		this->p[b].parent = a;
	else
	{
		this->p[a].parent = b;
		if (this->p[a].rank == this->p[b].rank)
		{
			this->p[a].rank++;
			this->p[b].rank++;
		}
	}
}
void DSU::aggreate(int a2[][2], int m)
{
	int a, b;
	for (int i=0;i<m;i++)
	{
		a = a2[i][0];
		b = a2[i][1];
		a = this->_find(this->p, a);
		b = this->_find(this->p, b);
		if (this->p[a].rank > this->p[b].rank)
			this->p[b].parent = a;
		else
		{
			this->p[a].parent = b;
			if (this->p[a].rank == this->p[b].rank)
			{
				this->p[a].rank++;
				this->p[b].rank++;
			}
		}
	}
}
bool DSU::search(int a, int b)
{
	a = this->_find(this->p, a);
	b = this->_find(this->p, b);
	return a==b;
}