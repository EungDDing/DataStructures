#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
	head = new Node; // 더미 노드 생성
	head->next = nullptr;
	cur = nullptr;
	before = nullptr;
	numOfData = 0;
}

void LinkedList::LInsert(Point* data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = head->next;
	head->next = newNode;
	numOfData++;
}

void LinkedList::LSortInsert(Point* pdata)
{
	Node* newNode = new Node;
	Node* pred = head;
	newNode->data = pdata;
	while (pred->next != nullptr && CompareData(newNode->data, pred->next->data))
	{
		pred = pred->next;
	}

	newNode->next = pred->next;
	pred->next = newNode;

	numOfData++;
}
bool LinkedList::LFirst(Point*& pdata)
{
	if (head->next == nullptr)
		return false;
	before = head;
	cur = head->next;
	pdata = cur->data;

	return true;
}

bool LinkedList::LNext(Point*& pdata)
{
	if (cur->next == nullptr)
		return false;
	before = cur;
	cur = cur->next;
	pdata = cur->data;

	return true;
}

Point* LinkedList::LRemove()
{
	Node* rpos = cur;
	Point* rdata = rpos->data;
	before->next = cur->next; // before를 선언한 이유
	cur = before;
	delete[] rpos;
	numOfData--;
	return rdata;
}

int LinkedList::LCount()
{
	return numOfData;
}

bool LinkedList::CompareData(Point*& p1, Point*& p2)
{
	if (p1->xpos < p2->xpos)
		return true;
	else if (p1->xpos == p2->xpos)
	{
		if (p1->ypos < p2->ypos)
		{
			return true;
		}
	}

	return false;
}
