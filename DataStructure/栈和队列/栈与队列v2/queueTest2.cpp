#include <iostream>
#include "queue.h"

using namespace std;

// 任务结构体
struct Task {
    int id;
    string description;
    Task(int id_, string desc_) : id(id_), description(desc_) {}
};

int main() {
    // 创建一个链队列来存储任务
    LinkedQueue<Task> taskQueue;

    // 添加一些任务到队列中
    taskQueue.push(Task(1, "Complete report"));
    taskQueue.push(Task(2, "Review code"));
    taskQueue.push(Task(3, "Test application"));
    taskQueue.push(Task(4, "Meet with team"));

    // 显示当前队列中的任务
    cout << "Current tasks in the queue:" << endl;
    while (!taskQueue.empty()) {
        Task currentTask = taskQueue.front();
        cout << "Task ID: " << currentTask.id << ", Description: " << currentTask.description << endl;
        taskQueue.pop();
    }

    // 添加新任务
    taskQueue.push(Task(5, "Prepare presentation"));
    taskQueue.push(Task(6, "Finalize project plan"));

    // 显示更新后的队列中的任务
    cout << "\nUpdated tasks in the queue:" << endl;
    while (!taskQueue.empty()) {
        Task currentTask = taskQueue.front();
        cout << "Task ID: " << currentTask.id << ", Description: " << currentTask.description << endl;
        taskQueue.pop();
    }
	
	system("pause");

    return 0;
}
