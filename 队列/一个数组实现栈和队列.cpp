#include <iostream>
#include <algorithm>

class CirDeque { // Ñ­»·Ë«¶Ë¶ÓÁÐ
public:
	CirDeque() 
	{
		memset(s, 0, sizeof(s));
		front = 0;
		rear = 0;
		capacity = 101;
	}

	void push_front(int x)
	{
		if (isFull()) {
			return;
		}
		front = (front + capacity - 1) % capacity;
		s[front] = x;
	}

	void push_rear(int x)
	{
		if (isFull()) {
			return;
		}
		s[rear] = x;
		rear = (rear + 1) % capacity;
	}

	int pop_front()
	{
		int x = s[front];
		front = (front + 1) % capacity;
		return x;
	}

	int pop_rear()
	{
		int x = s[rear];
		rear = (rear + capacity - 1) % capacity;
		return x;
	}

	int get_front()
	{
		return s[front];
	}

	int get_rear()
	{
		return s[(rear + capacity - 1) % capacity];
	}

	bool isEmpty()
	{
		return (front == rear);
	}

	bool isFull()
	{
		return ((rear + 1) % capacity) == front;
	}
private:
	int s[101];
	int front;
	int rear;
	int capacity;
};

class MyStack {
public:
	MyStack()
	{
		cirDeque = new CirDeque();
	}

	~MyStack()
	{
		if (cirDeque != nullptr) {
			delete cirDeque;
		}
	}

	void push(int x)
	{
		cirDeque->push_rear(x);
	}

	int pop()
	{
		int x = cirDeque->get_rear();
		cirDeque->pop_rear();
		return x;
	}

	int top()
	{
		return cirDeque->get_rear();
	}

	bool empty()
	{
		return cirDeque->isEmpty();
	}
private:
	CirDeque *cirDeque {nullptr};
};