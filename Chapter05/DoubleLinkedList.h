#pragma once

template <class T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node<T>* prev;
};

template <class T>
class DoubleLinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	Node<T>* cur;
	int numOfData;
public:
	class DoubleLinkedList();
	void LInsert(T pdata);		

	bool LFirst(T& pdata);
	bool LNext(T& pdata);
	bool LPrevious(T& pdata);

	T LRemove();
	int LCount();
};

template <class T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	head = new Node<T>;
	tail = new Node<T>;
	head->next = tail;
	head->prev = nullptr;
	tail->next = nullptr;
	tail->prev = head;
	cur = nullptr;
	numOfData = 0;
}

template <class T>
void DoubleLinkedList<T>::LInsert(T pdata)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = pdata;
	
	newNode->prev = tail->prev;
	tail->prev->next = newNode;
	
	newNode->next = tail;
	tail->prev = newNode;
	numOfData++;
}

template <class T>
bool DoubleLinkedList<T>::LFirst(T& pdata)
{
	if (head->next == tail)
		return false;

	cur = head->next;
	pdata = cur->data;
	return true;
}

template <class T>
bool DoubleLinkedList<T>::LNext(T& pdata)
{
	if (cur->next == tail)
		return false;

	cur = cur->next;
	pdata = cur->data;
	return true;
}

template <class T>
bool DoubleLinkedList<T>::LPrevious(T& pdata)
{
	if (cur->prev == head)
		return false;

	cur = cur->prev;
	pdata = cur->data;
	return true;
}

template <class T>
T DoubleLinkedList<T>::LRemove()
{
	Node<T>* rpos = cur;
	T rdata = rpos->data;

	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;

	
	return rdata;
}
template <class T>
int DoubleLinkedList<T>::LCount()
{
	return numOfData;
}