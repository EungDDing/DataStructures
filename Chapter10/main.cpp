#include <iostream>
#include "Sort.h"
using namespace std;

int main(void)
{
	int arr[5] = { 5, 3, 4, 1, 2 };
	
	InsertSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";

	return 0;
}