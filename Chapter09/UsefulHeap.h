#pragma once

template <class T>
class UsefulHeap
{
private:
	T heapArr[100];
	int numOfData;
public:
	UsefulHeap()
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
	int DataPriorityComp(T data1, T data2)
	{
		return data2 - data1;
	}
	int GetHighPriorityChildIdx(int idx) // 가장 높은 우선 순위의 자식의 idx 값 반환
	{
		if (GetLChildIdx(idx) > numOfData)
			return 0;
		else if (GetLChildIdx(idx) == numOfData)
			return GetLChildIdx(idx);
		else
		{
			if (DataPriorityComp(heapArr[GetLChildIdx(idx)], heapArr[GetRChildIdx(idx)]) < 0)
				return GetRChildIdx(idx);
			else
				return GetLChildIdx(idx);
		}
	}
	void HInsert(T data, int pri)
	{
		int idx = numOfData + 1;

		while (idx != 1) // 삽입시 노드의 index를 정하는 루프
		{
			if (DataPriorityComp(data, heapArr[GetParentIdx(idx)]) > 0)
			{
				heapArr[idx] = heapArr[GetParentIdx(idx)];
				idx = GetParentIdx(idx);
			}
			else
				break;
		}

		heapArr[idx] = data;
		numOfData += 1;
	}
	T HDelete()
	{
		T retData = heapArr[1];
		T lastElem = heapArr[numOfData];

		int parentIdx = 1;
		int childIdx;

		while (childIdx = GetHighPriorityChildIdx(parentIdx))
		{
			if (DataPriorityComp(lastElem, heapArr[childIdx]) >= 0)
				break;

			heapArr[parentIdx] = heapArr[childIdx];
			parentIdx = childIdx;
		}

		heapArr[parentIdx] = lastElem;
		numOfData -= 1;
		return retData;
	}
};