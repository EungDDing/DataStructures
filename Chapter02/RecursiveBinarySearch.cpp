#include <iostream>
using namespace std;

int RecursiveBS(int arr[], int first, int last, int target)
{
	if (first >= last)
		return -1;
	
	int mid = (first + last) / 2;
	if (target == arr[mid])
		return mid;
	else if (target > arr[mid])
		return RecursiveBS(arr, mid + 1, last, target);
	else if (target < arr[mid])
		return RecursiveBS(arr, first, mid - 1, target);
}

int main(void)
{
	int arr[] = { 1,3,5,7,9 };
	int idx;

	idx = RecursiveBS(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
	if (idx == -1)
		cout << "Å½»ö ½ÇÆĞ" << endl;
	else
		cout << "ÀÎµ¦½º : " << idx << endl;

	idx = RecursiveBS(arr, 0, sizeof(arr) / sizeof(int) - 1, 4);
	if (idx == -1)
		cout << "Å½»ö ½ÇÆĞ" << endl;
	else
		cout << "ÀÎµ¦½º : " << idx << endl;

	return 0;
}