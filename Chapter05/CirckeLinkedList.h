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
	void LInsert(T pdata);		// tail에 노드 추가
	void LInsertFront(T pdata); // head에 노드 추가

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
		newNode->next = tail->next; // tail이 가리키는 next 노드가 head 노드가 됨
		tail->next = newNode;
	}
	numOfData++;
}

// 조회하는 함수에서는 head(tail->next)부터 cur로 조회시작
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

	// 삭제할 노드를 tail이 가리키고 있을 때
	if (rpos == tail)
	{
		// 그 노드뿐이라면 tail을 NULL로
		if (tail == tail->next)
			tail = nullptr;
		// 아니라면 before를 가리키는 node를 가리키도록
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