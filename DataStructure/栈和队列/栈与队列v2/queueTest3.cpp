#include <iostream>
#include "queue.h" // 假设你的双端队列实现在名为 "ArrayDeque.h" 的头文件中

using namespace std;

int main() {
    ArrayDeque<int> deque(5);

    // 添加元素到队列的前后
    deque.pushBack(10);
    deque.pushBack(20);
    deque.pushFront(5);
    deque.pushFront(15);

    // 显示队列中的元素
    while (!deque.empty()) {
        cout << "Front element: " << deque.front() << ", Back element: " << deque.back() << endl;
        deque.popFront();
    }

    // 测试空队列
    cout << "Is deque empty? " << deque.empty() << endl;
	
	system("pause");

    return 0;
}
