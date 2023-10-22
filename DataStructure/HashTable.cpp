// HashTable
// 哈希函数：除留余数法
// 冲突解决：开放定址法  

#include<iostream>

using namespace std;


// HashTable Implemention  
#define NULLKEY -1
#define DELKEY -2
typedef int KeyType;

typedef struct {
	KeyType key;
	int count;		//探测次数  
}HashTable;


// 插入元素  
void InsertHT(HashTable ha[], int &n, int m, int p, KeyType k){
	int i=1, adr;
	adr = k % p;
	// 如果已存元素n=m, 则此处会陷入死循环
	while (ha[adr].key != NULLKEY && ha[adr].key != DELKEY){
		adr = (adr + 1) % m;
		i++;
	}
	ha[adr].key = k;
	ha[adr].count = i;
	n++;
}

// 建表  
void CreateHT(HashTable ha[], int &n, int m, int p, KeyType keys[], int n1){
	for (int i=0; i<m; i++){
		ha[i].key = NULLKEY;
		ha[i].count = 0;
	}
	for (int i=0; i<n1; i++){
		InsertHT(ha, n, m, p, keys[i]);
	}
}

// 删除指定元素  
bool DeleteHT(HashTable ha[], int &n, int m, int p, KeyType k){
	// 被删除的元素标记为DELKEY
	// 表至少要有一个元素
	int adr = k % p;
	while (ha[adr].key != NULLKEY && ha[adr].key != DELKEY){
		adr = (adr + 1) % m;
	}
	if (ha[adr].key == k){
		ha[adr].key = DELKEY;
		n--;
		return true;
	}
	else
		return false;
}

// 查找  

void SearchHT(HashTable ha[], int m, int p, KeyType k){
	int i=1, adr;
	adr = k % p;
	while (ha[adr].key != NULLKEY && ha[adr].key != k){
		i++;
		adr = (adr + 1) % m;
	}
	if (ha[adr].key == k)
		cout << "成功：关键字"<<k<<"，比较"<<i<<"次"<<endl;
	else
		cout << "失败：关键字"<<k<<"，比较"<<i<<"次"<<endl;
}


// 测试程序

int main(){
	int m = 13;
	int n = 0;
	int p = 13;
	int n1 = 8;
	HashTable ha[m];
	
	int keys[10] = {11, 13, 17, 19, 23, 29, 31, 37, 41, 43};
	
	cout <<"建表前元素数"<<n<<endl;
	CreateHT(ha, n, m, p, keys, n1);
	cout <<"建表后元素数"<<n<<endl;
	
	InsertHT(ha, n, m, p, keys[8]);
	cout <<"插入元素"<<keys[8]<<"当前表中元素"<<n<<endl;
	
	cout <<"查找元素"<<keys[8]<<endl;
	SearchHT(ha, m, p, keys[8]);
	cout <<"查找元素"<<keys[9]<<endl;
	SearchHT(ha, m, p, keys[9]);
	return 0;
}















