#include <iostream>
#include "CirckeLinkedList.h"
using namespace std;

int main(void)
{
	CircleLinkedList<int> list;
	int data, i;

	list.LInsert(3);
	list.LInsert(4);
	list.LInsert(5);
	list.LInsertFront(2);
	list.LInsertFront(1);

	if (list.LFirst(data))
	{
		cout << data << " ";

		for (i = 0; i < list.LCount() * 3 - 1; i++)
		{
			if (list.LNext(data))
				cout << data << " ";
		}
	}
	cout << endl;

	int nodeNum = list.LCount();

	if (nodeNum != 0)
	{
		list.LFirst(data);
		if (data % 2 == 0)
			list.LRemove();

		for (i = 0; i < nodeNum - 1; i++)
		{
			list.LNext(data);
			if (data % 2 == 0)
				list.LRemove();
		}
	}

	if (list.LFirst(data))
	{
		cout << data << " ";

		for (i = 0; i < nodeNum - 1; i++)
		{
			if (list.LNext(data))
				cout << data << " ";
		}
	}
	cout << endl;

	return 0;
}