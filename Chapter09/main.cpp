#include <iostream>
#include "UsefulHeap.h"
using namespace std;

int main(void)
{
	UsefulHeap<char> heap;

	heap.HInsert('A', 1);
	heap.HInsert('B', 2);
	heap.HInsert('C', 3);
	cout << heap.HDelete() << endl;

	heap.HInsert('A', 1);
	heap.HInsert('B', 2);
	heap.HInsert('C', 3);
	cout << heap.HDelete() << endl;

	while (!heap.HIsEmpty())
	{
		cout << heap.HDelete() << endl;
	}

	return 0;
}