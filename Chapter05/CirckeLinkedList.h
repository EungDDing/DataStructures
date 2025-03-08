#pragma once

template <class T>
class Node
{
public:
	T data;
	Node<T>* next;
};

template <class T>
class CircleLinkedList
{
private:
	Node<T>* tail;
	Node<T>* cur;
	Node<T>* before;
	int numOfData;
public:
	CircleLinkedList();
	void LInsert(T pdata);		// tail�� ��� �߰�
	void LInsertFront(T pdata); // head�� ��� �߰�

	bool LFirst(T& pdata);
	bool LNext(T& pdata);
	T LRemove();
	int LCount();
};

template <class T>
CircleLinkedList<T>::CircleLinkedList()
{
	tail = nullptr;
	cur = nullptr;
	before = nullptr;
	numOfData = 0;
}

template <class T>
void CircleLinkedList<T>::LInsert(T pdata)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = pdata;
	if (tail == nullptr)
	{
		tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = tail->next;
		tail->next = newNode;
		tail = newNode;
	}
	numOfData++;
}

template <class T>
void CircleLinkedList<T>::LInsertFront(T pdata)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = pdata;
	if (tail == nullptr)
	{
		tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = tail->next; // tail�� ����Ű�� next ��尡 head ��尡 ��
		tail->next = newNode;
	}
	numOfData++;
}

// ��ȸ�ϴ� �Լ������� head(tail->next)���� cur�� ��ȸ����
template <class T>
bool CircleLinkedList<T>::LFirst(T& pdata)
{
	if (tail == nullptr)
		return false;
	
	before = tail;
	cur = tail->next;
	pdata = cur->data;
	return true;
}

template <class T>
bool CircleLinkedList<T>::LNext(T& pdata)
{
	if (tail == nullptr)
		return false;

	before = cur;
	cur = cur->next;
	pdata = cur->data;
	return true;
}

template <class T>
T CircleLinkedList<T>::LRemove()
{
	Node<T>* rpos = cur;
	T rdata = rpos->data;

	// ������ ��带 tail�� ����Ű�� ���� ��
	if (rpos == tail)
	{
		// �� �����̶�� tail�� NULL��
		if (tail == tail->next)
			tail = nullptr;
		// �ƴ϶�� before�� ����Ű�� node�� ����Ű����
		else
			tail = before;
	}

	before->next = cur->next;
	cur = before;

	delete rpos;
	numOfData--;
	return rdata;
}

template <class T>
int CircleLinkedList<T>::LCount()
{
	return numOfData;
}