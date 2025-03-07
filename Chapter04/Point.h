#pragma once

class Point
{
private:
	int xpos;
	int ypos;
public:
	Point(int x = 0, int y = 0);
	void ShowPointPos();
	bool operator==(Point& p);

	friend class LinkedList;
};