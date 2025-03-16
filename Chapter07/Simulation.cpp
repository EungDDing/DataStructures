#include <iostream>
#include <cstdlib>
#include <ctime>
#include "CircleQueue.h"
using namespace std;

const int CUSTOMER_TIME = 15;

const int CHEESE = 0;
const int BULGOGI = 1;
const int DUBBLE = 2;

const int CHEESE_TIME = 12;
const int BULGOGI_TIME = 15;
const int DUBBLE_TIME = 24;

int main(void)
{
	int makeProcess = 0;
	int cheeseOrder = 0;
	int bulgogiOrder = 0;
	int dubbleOrder = 0;

	CircleQueue<int> queue;
	srand(time(NULL));

	for (int sec = 0; sec < 3600; sec++)
	{
		if (sec % CUSTOMER_TIME == 0)
		{
			switch (rand() & 3)
			{
			case CHEESE:
				queue.Enqueue(CHEESE_TIME);
				cheeseOrder += 1;
				break;
			case BULGOGI:
				queue.Enqueue(BULGOGI_TIME);
				bulgogiOrder += 1;
				break;
			case DUBBLE:
				queue.Enqueue(DUBBLE_TIME);
				dubbleOrder += 1;
				break;
			}
		}

		if (makeProcess <= 0 && !queue.QIsEmpty())
			makeProcess = queue.Dequeue();

		makeProcess--;
	}

	cout << "Simulation Report!" << endl;
	cout << " - cheese burger : " << cheeseOrder << endl;
	cout << " - bulgogi burger : " << bulgogiOrder << endl;
	cout << " - dubbke burger : " << dubbleOrder << endl;
	cout << " - waitin room size : " <<	QueueLen << endl;
	
	return 0;
}