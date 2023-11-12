#include<iostream>
#include"heap.h"


int main() {
	Heap<int> minHeap;

    // 插入操作
    minHeap.insert(3);
    minHeap.insert(1);
    minHeap.insert(4);
    minHeap.insert(2);
	

    // 打印堆的内容
    std::cout << "Heap after insertions: ";
    minHeap.printHeap();

    // 删除最值操作
    int minValue = minHeap.erase();
    std::cout << "Min value extracted: " << minValue << std::endl;

    // 打印删除最值后的堆内容
    std::cout << "Heap after extraction: ";
    minHeap.printHeap();

    // 堆化操作
    std::vector<int> values = {9, 5, 7, 1, 8};
    Heap<int> minHeap2(values);

    // 打印堆化后的堆内容
    std::cout << "Heap after buildHeap: ";
    minHeap2.printHeap();
	
	// 使用<<运算符进行打印
	std::cout<<"print heap by operator<<"<<std::endl;
	std::cout<<minHeap2;
	
	return 0;
}