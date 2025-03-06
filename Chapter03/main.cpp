#include <iostream>
#include "ArrayList.h"
#include "Point.h"
using namespace std;

int main(void)
{
	List list;
	Point* po;
	po = new Point(2, 1);
	list.LInsert(po);
	po = new Point(2, 2);
	list.LInsert(po);
	po = new Point(3, 1);
	list.LInsert(po);
	po = new Point(3, 2);
	list.LInsert(po);

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