#ifndef _QUEUE_H_
#define _QUEUE_H_

/**
顺序队：FIFIO

使用左闭右开区间[head, (head + count) % capacity)表示队列元素，循环数组实现
队空: count == 0
队满: count == capacity
入队: data[(head + count) % capacity] = e; ++count;
出队: head = (head + 1) % capacity; --count
*/

template <typename T> 
class ArrayQueue{
private:
	T *data;
	int head;
	int count;
	int capacity;
	
public:
	ArrayQueue(int capacity_):head(0),count(0),capacity(capacity_){
		data = new T[capacity_];
	}
	~ArrayQueue(){
		delete [] data;
	}
	bool empty(){return count == 0;}
	bool full(){return count == capacity;}
	int size() {return count;}
	T front();
	T back();
	void push(const T& e);
	void pop();
};
template <typename T> 
T ArrayQueue<T>::front() {
	if (count == 0) {
		throw "Empty queue exception!";
	}
	return data[head];
}
template <typename T>
T ArrayQueue<T>::back() {
	if (count == 0) {
		throw "Empty queue exception!";
	}
	return data[(head + count - 1) % capacity];
}
template <typename T>
void ArrayQueue<T>::push(const T& e) {
	if (count == capacity) {
		throw "Full queue exception!";
	}
	data[(head + count) % capacity] = e;
	++count;
}
template <typename T>
void ArrayQueue<T>::pop() {
	if (count == 0) {
		throw "Empty queue exception!";
	}
	head = (head + 1) % capacity;
	--count;
}

/**
链队

head, tail指针分别指向队头和队尾，单链表实现
队空: head 或 tail为空
入队: 队空, head = tail = e; 非空, tail = tail->next = e;
出队: 暂存队头元素, head == tail, head = tail = nullptr; head != tail, head = head->next;释放队头内存
*/
template <typename T> 
class LinkedQueue {
private:
	class QueueNode {
	public:
		T data;
		QueueNode *next;
		
		QueueNode(QueueNode *next_ = nullptr):next(next_){}
		QueueNode(const T& data_, QueueNode *next_ = nullptr):data(data_), next(next_){}
	};
	
	QueueNode *head;
	QueueNode *tail;
	int count;
	
public:
	LinkedQueue():head(nullptr),tail(nullptr),count(0){};
	~LinkedQueue();
	bool empty() {return tail == nullptr;}
	bool full() {return tail != nullptr;}
	int size() {return count;}
	T front();
	T back();
	void push(const T& e);
	void pop();
};
template <typename T> 
LinkedQueue<T>::~LinkedQueue() {
	tail = nullptr;
	while (head != nullptr) {
		tail = head;
		head = head->next;
		delete tail;
	}
}
template <typename T> 
T LinkedQueue<T>::front() {
	if (head == nullptr) {
		throw "Empty queue exception!";
	}
	return head->data;
}
template <typename T>
T LinkedQueue<T>::back() {
	if (tail == nullptr) {
		throw "Empty queue exception!";
	}
	return tail->data;
}
template <typename T>
void LinkedQueue<T>::push(const T& e) {
	++count;
	if (head == nullptr && tail == nullptr) {
		head = tail = new QueueNode(e);
		return;
	}
	tail = tail->next = new QueueNode(e);
}
template <typename T>
void LinkedQueue<T>::pop() {
	if (tail == nullptr) {
		throw "Empty queue exception!";
	}
	--count;
	QueueNode *h = head;
	if (head == tail) {
		head = tail = nullptr;
		return;
	}
	head = head->next;
	delete h;
}

/**
双端队列：FIFIO

使用左闭右开区间[head, (head + count) % capacity)表示队列元素，循环数组实现
队尾删除: --count;
队头插入: (head - 1 + capacity) % capacity; ++count;
*/

template <typename T> 
class ArrayDeque{
private:
	T *data;
	int head;
	int count;
	int capacity;
	
public:
	ArrayDeque(int capacity_):head(0),count(0),capacity(capacity_){
		data = new T[capacity_];
	}
	~ArrayDeque(){
		delete [] data;
	}
	bool empty(){return count == 0;}
	bool full(){return count == capacity;}
	int size() {return count;}
	T front();
	T back();
	void pushFront(const T& e);
	void pushBack(const T& e);
	void popFront();
	void popBack();
};
template <typename T> 
T ArrayDeque<T>::front() {
	if (count == 0) {
		throw "Empty queue exception!";
	}
	return data[head];
}
template <typename T>
T ArrayDeque<T>::back() {
	if (count == 0) {
		throw "Empty queue exception!";
	}
	return data[(head + count - 1) % capacity];
}
template <typename T>
void ArrayDeque<T>::pushFront(const T& e) {
	if (count == capacity) {
		throw "Full queue exception!";
	}
	head = (head - 1 + capacity) % capacity;
	data[head] = e;
	++count;
}
template <typename T>
void ArrayDeque<T>::pushBack(const T& e) {
	if (count == capacity) {
		throw "Full queue exception!";
	}
	data[(head + count) % capacity] = e;
	++count;
}
template <typename T>
void ArrayDeque<T>::popFront() {
	if (count == 0) {
		throw "Empty queue exception!";
	}
	head = (head + 1) % capacity;
	--count;
}
template <typename T>
void ArrayDeque<T>::popBack() {
	if (count == 0) {
		throw "Empty queue exception!";
	}
	--count;
}
#endif