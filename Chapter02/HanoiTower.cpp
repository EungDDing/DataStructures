#include <iostream>
using namespace std;

static int COUNT = 0;
void HanoiTowerMove(int num, char from, char by, char to)
{
	COUNT++;
	if (num == 1)
	{
		cout << "원반 1을 " << from << "에서 " << to << "로 이동" << endl;
		cout << COUNT;
	}
	else
	{
		HanoiTowerMove(num - 1, from, to, by);
		cout << "원반 " << num << "을 " << from << "에서 " << to << "로 이동" << endl;
		HanoiTowerMove(num - 1, by, from, to);
	}
}

int main(void)
{
	HanoiTowerMove(3, 'A', 'B', 'C');
	return 0;
}