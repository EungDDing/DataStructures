#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

const int QueueLen = 100;

template <class T>
class Node
{
public:
	T data;
	Node<T>* next;
};

template <class T>
class ListQueue
{
private:
	Node<T>* front;
	Node<T>* rear;
public:
	ListQueue()
	{
		front = nullptr;
		rear = nullptr;
	}
	bool QIsEmpty()
	{
		if (front == nullptr)
			return true;
		else
			return false;
	}
	void Enqueue(T data)
	{
		Node<T>* newNode = new Node<T>;
		newNode->next = nullptr;
		newNode->data = data;
		
		if (QIsEmpty())
		{
			front = newNode;
			rear = newNode;
		}
		else
		{
			rear->next = newNode; // 다음 노드가 newNode를 가리키도록
			rear = newNode;		  // rear가 newNode를 가리키도록
		}
	}
	const T& Dequeue()
	{
		Node<T>* delNode;
		T retData;

		if (QIsEmpty())
		{
			cout << "Queue Memory Error!" << endl;
			exit(-1);
		}
		
		delNode = front;
		retData = delNode->data;
		front = front->next;

		delete delNode;
		return retData;
	}
	const T& QPeek()
	{
		if (QIsEmpty())
		{
			cout << "Queue Memory Error!" << endl;
			exit(-1);
		}

		return front->data;
	}
};