#pragma once
#include "Point.h"

constexpr int LIST_LEN = 100;

class List
{
private:
	Point* arr[LIST_LEN];	 // 리스트의 저장소 배열
	int numOfData;	 // 데이터의 수
	int curPosition; // 데어터 참조 위치
public:
	List();
	void LInsert(Point* data);
	
	bool LFirst(Point*& data);
	bool LNext(Point*& data);

	Point* LRemove();  // 최근 조회가 이뤄진 데이터 삭제, 삭제된 데이터 반환
	int LCount();
};

