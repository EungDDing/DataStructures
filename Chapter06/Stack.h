#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class Stack
{
private:
	T stackArr[100];
	int topIndex;
public:
	Stack();
	bool SIsEmpty();
	void SPush(T data);
	const T& SPop();
	const T& SPeek();
};

template <class T>
Stack<T>::Stack()
{
	topIndex = -1;
}

template <class T>
bool Stack<T>::SIsEmpty()
{
	return topIndex == -1;
}

template <class T>
void Stack<T>::SPush(T data)
{
	topIndex += 1;
	stackArr[topIndex] = data;
}

template <class T>
const T& Stack<T>::SPop()
{
	int rIdx; // 삭제할 데이터의 인덱스
	if (SIsEmpty())
	{
		cout << "Stack memory error!" << endl;
		exit(-1);
	}

	rIdx = topIndex;
	topIndex -= 1;

	return stackArr[rIdx];
}

template <class T>
const T& Stack<T>::SPeek()
{
	if (SIsEmpty())
	{
		cout << "Stack memory error!" << endl;
		exit(-1);
	}

	return stackArr[topIndex];
}