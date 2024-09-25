#include <iostream>
using namespace std;

int arr[] = { 3, 2, 7, 116, 62, 235, 1, 23, 55, 77 };
int n = 10;
int pivot = arr[0];
int l = 1;
int r = 9;

void quick_sort(int st, int en)
{
	if (en <= st + 1) return;
	int pivot = arr[st];
	int l = st + 1;
	int r = en - 1;
	while (1)
	{
		while (l <= r && arr[l] <= pivot) l++;
		while (l <= r && arr[r] > pivot) r++;
		if (l > r) break;
		swap(arr[l], arr[r]);
	}

	swap(arr[st], arr[r]);
	quick_sort(st, r);
	quick_sort(r + 1, en);
}

int main()
{

	return 0;
}