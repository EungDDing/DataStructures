#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class Node
{
public:
	T data;
	Node<T>* prev;
	Node<T>* next;
};

template <class T>
class Deque
{
private:
	Node<T>* head;
	Node<T>* tail;
public:
	Deque()
	{
		head = nullptr;
		tail = nullptr;
	}
	bool DQIsEmpty()
	{
		if (head == nullptr)
			return true;
		else
			return false;
	}
	void DQAddFirst(T data)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = data;
		newNode->next = head;

		if (DQIsEmpty())
		{
			tail = newNode;
		}
		else
		{
			head->prev = newNode;
		}
		
		newNode->prev = nullptr;
		head = newNode;
	}
	void DQAddLast(T data)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = data;
		newNode->prev = tail;

		if (DQIsEmpty())
		{
			head = newNode;
		}
		else
		{
			tail->next = newNode;
		}

		newNode->next = nullptr;
		tail = newNode;
	}
	const T DQRemoveFirst()
	{
		Node<T>* rnode = head;
		T rdata;

		if (DQIsEmpty())
		{
			cout << "Dequeue Memory Empty!" << endl;
			exit(-1);
		}

		rdata = rnode->data;
		head = head->next;
		delete rnode;

		if (head == nullptr) // 덱에 데이터가 없음
			tail = nullptr;
		else
			head->prev = nullptr;

		return rdata;
	}
	const T DQRemoveLast()
	{
		Node<T>* rnode = tail;
		T rdata;

		if (DQIsEmpty())
		{
			cout << "Dequeue Memory Empty!" << endl;
			exit(-1);
		}

		rdata = rnode->data;
		tail = tail->prev;
		delete rnode;

		if (tail == nullptr)
			head = nullptr;
		else
			tail->next = nullptr;

		return rdata;
	}
	const T& DQGetFirst()
	{
		if (DQIsEmpty())
		{
			cout << "Dequeue Memory Empty!" << endl;
			exit(-1);
		}

		return head->data;
	}
	const T& DQGetLast()
	{
		if (DQIsEmpty())
		{
			cout << "Dequeue Memory Empty!" << endl;
			exit(-1);
		}

		return tail->data;
	}
};