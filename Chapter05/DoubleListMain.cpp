#include <iostream>
#include "DoubleLinkedList.h"
using namespace std;

int main(void)
{
	DoubleLinkedList<int> list;
	int data;

	list.LInsert(1);
	list.LInsert(2);
	list.LInsert(3);
	list.LInsert(4);
	list.LInsert(5);
	list.LInsert(6);
	list.LInsert(7);
	list.LInsert(8);

	if (list.LFirst(data))
	{
		cout << data << " ";
		
		while (list.LNext(data))
			cout << data << " ";

		while (list.LPrevious(data))
			cout << data << " ";

		cout << endl << endl;
	}

	if (list.LFirst(data))
	{
		if (data % 2 == 0)
			list.LRemove();
		while (list.LNext(data))
		{
			if (data % 2 == 0)
				list.LRemove();
		}
	}

	if (list.LFirst(data))
	{
		cout << data << " ";

		while (list.LNext(data))
			cout << data << " ";

		cout << endl << endl;
	}

	return 0;
}