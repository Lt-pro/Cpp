#include <iostream>
#include "queue.h" // 假设你的队列实现在名为 "Queue.h" 的头文件中

using namespace std;

int main() {
    // 测试顺序队列(ArrayQueue)
    cout << "Testing ArrayQueue:" << endl;
    ArrayQueue<int> arrQueue(5);

    // 测试空队列
    cout << "Is ArrayQueue empty? " << arrQueue.empty() << endl;

    // 添加元素到队列
    arrQueue.push(10);
    arrQueue.push(20);
    arrQueue.push(30);

    // 获取队首和队尾元素
    cout << "Front element: " << arrQueue.front() << endl;
    cout << "Back element: " << arrQueue.back() << endl;

    // 移除队首元素并显示队列大小
    arrQueue.pop();
    cout << "Size after removing one element: " << arrQueue.size() << endl;

    // 测试链队列(LinkedQueue)
    cout << "\nTesting LinkedQueue:" << endl;
    LinkedQueue<string> linkedQueue;

    // 添加元素到链队列
    linkedQueue.push("Apple");
    linkedQueue.push("Banana");
    linkedQueue.push("Orange");

    // 获取队首和队尾元素
    cout << "Front element: " << linkedQueue.front() << endl;
    cout << "Back element: " << linkedQueue.back() << endl;

    // 移除队首元素并显示队列大小
    linkedQueue.pop();
    cout << "Size after removing one element: " << linkedQueue.size() << endl;
	
	system("pause");

    return 0;
}
