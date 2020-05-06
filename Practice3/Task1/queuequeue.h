#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class Queue;
template<class T>
Queue<T> queuing(const Queue<T>& a, const Queue<T>& b);


template <class T>
class Queue
{
	//friend queue queuing <T>(queue<T>& a,queue<T>& b);
	friend Queue queuing <T>(const Queue<T>& a, const Queue<T>& b);

private:


	int size;
	T* array;
	int head, tail;
	bool isLooped;
	bool isFull() { return this->head == this->tail && this->isLooped; }
	bool isEmpty() { return this->head == this->tail && !this->isLooped; }

public:

	


	Queue(int size)
	{
		this->size = size;
		this->array = new T[this->size];
		this->head = 0;
		this->tail = 0;
		this->isLooped = false;
	}


	Queue(const Queue& queue)
	{
		this->size = queue.size;
		this->array = new T[this->size];
		copy(queue.array, queue.array + queue.size, this->array);
		this->head = queue.head;
		this->tail = queue.tail;
		this->isLooped = queue.isLooped;
	}


	~Queue() { delete[] array; }


	void push(T element)
	{
		if (this->isFull())
			throw out_of_range("queue is full");
		this->array[this->tail] = element;
		this->tail = (this->tail + 1) % this->size;
		if (isEmpty())
			this->isLooped = true;
	}


	T pop()
	{
		if (this->isEmpty())
			throw out_of_range("queue is empty");
		T element = this->array[this->head];
		this->head = (this->head + 1) % this->size;
		if (isFull())
			this->isLooped = false;
		return element;
	}

	
	
};

template<class T>
Queue<T> queuing(const Queue<T>& a, const Queue<T>& b) 
{
	int size = a.size + b.size;
	Queue<T> queue = Queue<T>(size);
	int pointer = a.head;
	bool isLooped = false;
	while (pointer != a.tail || pointer == a.tail && isLooped != a.isLooped) 
	{
		queue.push(a.array[pointer]);
		pointer = (pointer + 1) % a.size;
		if (pointer == 0)
			isLooped = true;
	}
	pointer = b.head;
	isLooped = false;
	while (pointer != b.tail || pointer == b.tail && isLooped != b.isLooped) 
	{

		queue.push(b.array[pointer]);
		pointer = (pointer + 1) % b.size;
		if (pointer == 0)
			isLooped = true;
	}
	return queue;
}
