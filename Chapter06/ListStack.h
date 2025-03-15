#pragma once
#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class Node
{
public:
	T data;
	Node<T>* next;
};
template <class T>
class ListStack
{
private:
	Node<T>* head;
public:
	ListStack();
	bool SIsEmpty();
	void SPush(T data);
	const T SPop();
	const T& SPeek();
};

template <class T>
ListStack<T>::ListStack()
{
	head = nullptr;
}

template <class T>
bool ListStack<T>::SIsEmpty()
{
	return head == nullptr;
}

template <class T>
void ListStack<T>::SPush(T data)
{
	Node<T>* newNode = new Node<T>;

	newNode->data = data;
	newNode->next = head;

	head = newNode;
}

template <class T>
const T ListStack<T>::SPop()
{
	T data;
	Node<T>* rNode;

	if (SIsEmpty())
	{
		cout << "Stack memory error!" << endl;
		exit(-1);
	}

	data = head->data;
	rNode = head;
	head = head->next;
	delete rNode;
	return data;
}

template <class T>
const T& ListStack<T>::SPeek()
{
	if (SIsEmpty())
	{
		cout << "Stack memory error!" << endl;
		exit(-1);
	}

	return head->data;
}