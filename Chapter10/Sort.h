#pragma once

void BubbleSort(int arr[], int n)
{
	int temp;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i; j < (n - i) - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void SelectSort(int arr[], int n)
{
	int temp;
	int maxIndex;

	for (int i = 0; i < n - 1; i++)
	{
		maxIndex = i;
		
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[maxIndex])
				maxIndex = j;
		}

		temp = arr[i];
		arr[i] = arr[maxIndex];
		arr[maxIndex] = temp;
	}
}

void InsertSort(int arr[], int n)
{
	int i, j;
	int insertData;

	for (i = 0; i < n; i++)
	{
		insertData = arr[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > insertData)
				arr[j + 1] = arr[j];
			else
				break;
		}

		arr[j + 1] = insertData;
	}
}