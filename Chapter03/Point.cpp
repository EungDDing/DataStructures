#include <iostream>
#include "Point.h"
using namespace std;

Point::Point(int x, int y) : xpos(x), ypos(y)
{ }

void Point::ShowPointPos()
{
	cout << "(" << xpos << ", " << ypos << ")" << endl;
}

bool Point::operator==(Point& p)
{
	if (xpos == p.xpos && ypos == p.ypos)
		return true;
	else
		return false;
}