#include <iostream>
#include <vector>

class MinHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] < heap[parentIndex]) {
                std::swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // 插入操作
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // 删除最值操作
    int extractMin() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }

        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return minVal;
    }

    // 堆化操作（自下而上）
    void buildHeap(const std::vector<int>& values) {
        heap = values;

        for (int i = (heap.size() - 1) / 2; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    // 打印堆的内容
    void printHeap() {
        for (int value : heap) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MinHeap minHeap;

    // 插入操作
    minHeap.insert(3);
    minHeap.insert(1);
    minHeap.insert(4);
    minHeap.insert(2);

    // 打印堆的内容
    std::cout << "Heap after insertions: ";
    minHeap.printHeap();

    // 删除最值操作
    int minValue = minHeap.extractMin();
    std::cout << "Min value extracted: " << minValue << std::endl;

    // 打印删除最值后的堆内容
    std::cout << "Heap after extraction: ";
    minHeap.printHeap();

    // 堆化操作
    std::vector<int> values = {9, 5, 7, 1, 8};
    minHeap.buildHeap(values);

    // 打印堆化后的堆内容
    std::cout << "Heap after buildHeap: ";
    minHeap.printHeap();

    return 0;
}
