#include<iostream>
#include<ctime>
#include<cstdlib>
#include"heap.h"

using namespace std;

const int NUM = 40;
const int MOD = 1024;
int main() {
	Heap<int> minHeap;
	int e;
	srand((unsigned)time(NULL));
	
	for (int i=0; i<NUM; i++) {
		e = rand()% MOD;
		minHeap.insert(e);
	}
	
	minHeap.printHeap();
	
	cout<<"the number of heap "<<minHeap.size()<<endl;
	while (!minHeap.empty()) {
		cout<<minHeap.erase()<<" ";
	}
	cout<<endl;
	
	return 0;
}