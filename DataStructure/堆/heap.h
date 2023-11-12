#ifndef _HEAP_H_
#define _HEAP_H_

#include <iostream>
#include <vector>


/**
* 动态数组实现的最小堆，参数类型支持比较运算符和<<运算符
*/

template <class T> 
class Heap {
private:
	std::vector<T> heap;
	
	// 自下而上堆化
	void heapifyUp(int index);
	
	// 自上而下堆化
	void heapifyDown(int index);
	
public:
	// 默认构造，拷贝，赋值，析构即可
	Heap(){}
	Heap(const std::vector<T>& data);	//无序元素建堆
	
	// 堆顶插入元素
	void insert(const T& e);
	
	// 移除最小的元素
	T erase();
	
	// 堆元素是否为空
	bool empty(){return heap.empty();}
	
	// 堆大小
	int size(){return heap.size();}
	
	// 打印函数
	void printHeap();
	
	
	// 重载运算符<<
	template <typename TT> 
	friend std::ostream& operator<<(std::ostream& os, const Heap<TT>& heap);
};

template <class T>
Heap<T>::Heap(const std::vector<T>& data) {
	heap = data;
	
	for (int i=(heap.size()-1)/2; i>=0; i--)
		heapifyDown(i);
}

template <class T> 
void Heap<T>::heapifyUp(int index) {
	T tmp = heap[index];
	
	while (index > 0) {
		int parentIndex = (index - 1) / 2;
		if (heap[parentIndex] > tmp) {
			heap[index] = heap[parentIndex];
			index = parentIndex;
		} else
			break;
	}
	heap[index] = tmp;
}

template <class T> 
void Heap<T>::heapifyDown(int index) {
	T tmp = heap[index];
	
	while (2*index+1 < heap.size()) {
		int leftIndex = 2 * index + 1;
		int rightIndex = 2 * index + 2;
		int smallest = leftIndex;
		
		if (rightIndex<heap.size() && heap[rightIndex]<heap[smallest])
			smallest = rightIndex;
		
		if (tmp > heap[smallest]) {
			heap[index] = heap[smallest];
			index = smallest;
		} else 
			break;
	}
	heap[index] = tmp;
}

template <class T>
void Heap<T>::insert(const T& e) {
	heap.push_back(e);
	heapifyUp(heap.size()-1);
}

template <class T>
T Heap<T>::erase() {
	if (heap.empty())
		throw std::out_of_range("Heap is empty");
	
	T top = heap[0];
	heap[0] = heap.back();
	heap.pop_back();
	heapifyDown(0);
	
	return top;
}

template <class T>
void Heap<T>::printHeap() {
	if (heap.empty()) {
		std::cout<<"Heap is empty."<<std::endl;
		return;
	}
	
	for (T e: heap)
		std::cout<<e<<" ";
	std::cout<<std::endl;
}

template <typename TT> 
std::ostream& operator<<(std::ostream& os, const Heap<TT>& heap) {
	if (heap.heap.empty()) {
		std::cout<<"Heap is empty."<<std::endl;
		return os;
	}
	
	for (TT e: heap.heap)
		std::cout<<e<<" ";
	return os;
}

#endif