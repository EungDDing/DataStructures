#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(void)
{
	LinkedList list;
	Point* po;
	po = new Point(3, 1);
	list.LSortInsert(po);
	po = new Point(1, 2);
	list.LSortInsert(po);
	po = new Point(4, 2);
	list.LSortInsert(po);
	po = new Point(4, 1);
	list.LSortInsert(po);
	po = new Point(2, 2);
	list.LSortInsert(po);
	po = new Point(1, 1);
	list.LSortInsert(po);

	cout << "현재 데이터의 수 : " << list.LCount() << endl;

	if (list.LFirst(po))
	{
		po->ShowPointPos();

		while (list.LNext(po))
			po->ShowPointPos();
	}
	cout << endl << endl;

	Point comPo(2, 2);
	if (list.LFirst(po))
	{
		if (*po == comPo)
		{
			list.LRemove();
			delete po;
		}

		while (list.LNext(po))
		{
			if (*po == comPo)
			{
				list.LRemove();
				delete po;
			}
		}
	}
	cout << "현재 데이터의 수 : " << list.LCount() << endl;

	if (list.LFirst(po))
	{
		po->ShowPointPos();

		while (list.LNext(po))
			po->ShowPointPos();
	}
	cout << endl << endl;

	return 0;
}