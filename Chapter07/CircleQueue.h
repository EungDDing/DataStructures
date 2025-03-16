#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

const int QueueLen = 100;

template <class T>
class CircleQueue
{
private:
	int front;
	int rear;
	T queueArr[QueueLen];
public:
	CircleQueue(int f = 0, int r = 0) : front(f), rear(r)
	{ }
	bool QIsEmpty()
	{
		if (front == rear)
			return true;
		else
			return false;
	}
	int NextPosIdx(int pos)
	{
		if (pos == QueueLen - 1) // 배열의 마지막 요소의 인덱스 값이라면 다시 0으로
			return 0;
		else
			return pos + 1;
	}
	void Enqueue(T data)
	{
		if (NextPosIdx(rear) == front) // 큐가 꽉 찼다면
		{
			cout << "Queue Memory Error!" << endl;
			exit(-1);
		}

		rear = NextPosIdx(rear);
		queueArr[rear] = data;
	} 
	const T& Dequeue()
	{
		if (QIsEmpty())
		{
			cout << "Queue Memory Error!" << endl;
			exit(-1);
		}
		
		front = NextPosIdx(front);
		return queueArr[front];
	}
	const T& QPeek()
	{
		if (QIsEmpty())
		{
			cout << "Queue Memory Empty!" << endl;
			exit(-1);
		}

		return queueArr[NextPosIdx(front)];
	}
};