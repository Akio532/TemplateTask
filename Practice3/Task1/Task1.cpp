// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "queuequeue.h"
//include <queuequeue>
using namespace std;

int main()
{
	Queue<int> queue1 = Queue <int>(1);
	queue1.push(1);
	Queue<int> queue2 = Queue<int>(5);
	queue2.push(2);
	queue2.push(3);
	queue2.push(4);
	queue2.push(5);
	queue2.push(6);
	Queue<int> queue3 = queuing(queue1, queue2);
	for (int i = 0; i < 5; i++)
		cout << queue3.pop() << endl;
	return 0;
    //std::cout << "Hello World!\n";
}
