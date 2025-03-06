#pragma once
#include "Point.h"

constexpr int LIST_LEN = 100;

class List
{
private:
	Point* arr[LIST_LEN];	 // ����Ʈ�� ����� �迭
	int numOfData;	 // �������� ��
	int curPosition; // ������ ���� ��ġ
public:
	List();
	void LInsert(Point* data);
	
	bool LFirst(Point*& data);
	bool LNext(Point*& data);

	Point* LRemove();  // �ֱ� ��ȸ�� �̷��� ������ ����, ������ ������ ��ȯ
	int LCount();
};

