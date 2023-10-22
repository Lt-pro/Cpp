#include <iostream>
#include "linearList.h"

using namespace std;


/*
//顺序表结构体实现
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqListS;
*/

void CreateList(SqListS *&L, ElemType a[], int n){
	for(int i=0;i<n;i++){
		L->data[i] = a[i];
		L->length++;
	}
}
void InitList(SqListS *&L){
	L = new SqListS;
	L->length = 0;
}
void DestoryList(SqListS *&L){
	delete L;
}
bool ListEmpty(SqListS *L){
	return L->length==0;
}
int ListLength(SqListS *L){
	return L->length;
}
void DispList(SqListS *L){
	for(int i=0;i<L->length;i++){
		cout<<i+1<<L->data[i]<<endl;
	}
}
bool GetElem(SqListS *L, int i, ElemType &e){
	if(i<1 || i>L->length){
		return false;
	}
	e = L->data[--i];
	return true;
}
int LocateElem(SqListS *L, ElemType e){
	int j=0, i=0;
	while(i<L->length && L->data[i]!=e){
		i++;
	}
	if (i>=L->length){
		return 0;
	}
	else{
		return i+1;
	}
}
bool ListInsert(SqListS *&L, int i, ElemType e){
	if (i<1 || i>L->length+1){
		return false;
	}
	--i;
	for (int j=L->length;j>i;j--){
		L->data[j] = L->data[j-1];
	}
	L->data[i] = e;
	L->length++;
	return true;
}
bool ListDelete(SqListS *&L, int i, ElemType &e){
	if (i<1 || i>L->length){
		return false;
	}
	i--;
	for (int j=i;j<L->length-1;j++){
		L->data[j] = L->data[j+1];
	}
	L->length--;
	return true;
}





