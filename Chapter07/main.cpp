#include <iostream>
#include "ListQueue.h"
using namespace std;

int main(void)
{
	ListQueue<int> queue;

	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);
	queue.Enqueue(4);
	queue.Enqueue(5);

	while (!queue.QIsEmpty())
		cout << queue.Dequeue() << " ";

	return 0;
}