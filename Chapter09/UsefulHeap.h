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
	int GetParentIdx(int idx) // �θ��� index ��
	{
		return idx / 2;
	}
	int GetLChildIdx(int idx) // ���� �ڽ��� index ��
	{
		return idx * 2;
	}
	int GetRChildIdx(int idx) // ������ �ڽ��� index ��
	{
		return idx * 2 + 1;
	}
	int DataPriorityComp(T data1, T data2)
	{
		return data2 - data1;
	}
	int GetHighPriorityChildIdx(int idx) // ���� ���� �켱 ������ �ڽ��� idx �� ��ȯ
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

		while (idx != 1) // ���Խ� ����� index�� ���ϴ� ����
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