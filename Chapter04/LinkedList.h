#pragma once
#include "Point.h"

class Node
{
public:
	Point* data;
	Node* next;
};

class LinkedList
{
private:
	Node* head;
	Node* cur;
	Node* before;
	int numOfData;
public:
	LinkedList();
	void LInsert(Point* data);
	void LSortInsert(Point* pdata); // 정렬 Insert
	bool LFirst(Point*& pdata);
	bool LNext(Point*& pdata);
	Point* LRemove();
	int LCount();
	bool CompareData(Point*& p1, Point*& p2); // 정렬을 위한 함수
};