#include <iostream>
#include "ArrayList.h"
#include "Point.h"
using namespace std;

List::List()
{
	numOfData = 0;
	curPosition = -1;
}

void List::LInsert(Point* data)
{
	if (numOfData >= LIST_LEN)
	{
		cout << "저장이 불가능합니다." << endl;
		return;
	}

	arr[numOfData] = data;
	numOfData++;
}

bool List::LFirst(Point*& pdata)
{
	if (numOfData == 0)
		return false;

	curPosition = 0;
	pdata = arr[0];
	return true;
}

bool List::LNext(Point*& pdata)
{
	if (curPosition >= numOfData - 1)
		return false;

	curPosition++;
	pdata = arr[curPosition];
	return true;
}

Point* List::LRemove()
{
	int rpos = curPosition;
	int num = numOfData;
	int i;
	Point* rdata = arr[rpos];

	// 삭제를 위해서 데이터를 앞으로 이동시킴, 삭제할 부분의 데이터가 덮어씌어짐
	for (i = rpos; i < num - 1; i++)
		arr[i] = arr[i + 1]; 

	numOfData--;
	curPosition--;
	return rdata;
}

int List::LCount()
{
	return numOfData;
}