#pragma once

template <class T>
class HeapElement
{
public:
	int priority;
	T data;
	
	HeapElement()
	{ }
	HeapElement(T data, int pri) : data(data), priority(pri)
	{ }
};

template <class T>
class Heap
{
private:
	HeapElement<T> heapArr[100];
	int numOfData;
public:
	Heap()
	{
		numOfData = 0;
	}
	bool HIsEmpty()
	{
		if (numOfData == 0)
			return true;
		else
			return false;
	}
	int GetParentIdx(int idx) // 부모의 index 값
	{
		return idx / 2;
	}
	int GetLChildIdx(int idx) // 왼쪽 자식의 index 값
	{
		return idx * 2;
	}
	int GetRChildIdx(int idx) // 오른쪽 자식의 index 값
	{
		return idx * 2 + 1;
	}
	int GetHighPriorityChildIdx(int idx) // 가장 높은 우선 순위의 자식의 idx 값 반환
	{
		if (GetLChildIdx(idx) > numOfData)
			return 0;
		else if (GetLChildIdx(idx) == numOfData)
			return GetLChildIdx(idx);
		else
		{
			if (heapArr[GetLChildIdx(idx)].priority > heapArr[GetRChildIdx(idx)].priority)
				return GetRChildIdx(idx);
			else
				return GetLChildIdx(idx);
		}
	}
	void HInsert(T data, int pri)
	{
		int idx = numOfData + 1;
		HeapElement<T> nelem(data, pri);

		while (idx != 1) // 삽입시 노드의 index를 정하는 루프
		{
			if (pri < heapArr[GetParentIdx(idx)].priority)
			{
				heapArr[idx] = heapArr[GetParentIdx(idx)];
				idx = GetParentIdx(idx);
			}
			else
				break;
		}

		heapArr[idx] = nelem;
		numOfData += 1;
	}
	T HDelete()
	{
		T retData = heapArr[1].data;
		HeapElement<T> lastElem = heapArr[numOfData];

		int parentIdx = 1;
		int childIdx;

		while (childIdx = GetHighPriorityChildIdx(parentIdx))
		{
			if (lastElem.priority <= heapArr[childIdx].priority)
				break;

			heapArr[parentIdx] = heapArr[childIdx];
			parentIdx = childIdx;
		}

		heapArr[parentIdx] = lastElem;
		numOfData -= 1;
		return retData;
	}
};