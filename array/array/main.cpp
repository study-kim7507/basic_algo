#include <iostream>
#include <algorithm>

void insert(int idx, int num, int arr[], int& len);
void erase(int idx, int arr[], int& len);
void printArr(int arr[], int& len);

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6 };
	int len = 6;
	insert(2, 10, arr, len);
	erase(2, arr, len);
	printArr(arr, len);
	return 0;
}

void insert(int idx, int num, int arr[], int& len)
{
	for (int i = len; i > idx; i--)
	{
		arr[i] = arr[i - 1];
	}

	arr[idx] = num;
	len++;
}

void erase(int idx, int arr[], int& len)
{
	len--;
	for (int i = idx; i < len; i++)
	{
		arr[i] = arr[i + 1];
	}
}

void printArr(int arr[], int& len)
{
	for (int i = 0; i < len; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}