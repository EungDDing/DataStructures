#include <iostream>
#include "Deque.h"
using namespace std;

int main(void)
{
	Deque<int> deque;

	deque.DQAddFirst(3);
	deque.DQAddFirst(2);
	deque.DQAddFirst(1);

	deque.DQAddLast(4);
	deque.DQAddLast(5);
	deque.DQAddLast(6);

	while (!deque.DQIsEmpty())
		cout << deque.DQRemoveFirst() << " ";

	deque.DQAddFirst(3);
	deque.DQAddFirst(2);
	deque.DQAddFirst(1);

	deque.DQAddLast(4);
	deque.DQAddLast(5);
	deque.DQAddLast(6);

	while (!deque.DQIsEmpty())
		cout << deque.DQRemoveLast() << " ";

	return 0;
}