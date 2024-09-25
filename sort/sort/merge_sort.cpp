#include <iostream>
using namespace std;

int arr[] = { 11, 2, 4, 1, 8, 7, 9, 13, 10, 3 };
int temp[10];

void merge(int st, int en)
{
	int mid = (st + en) / 2;
	int lidx = st;
	int ridx = mid;
	for (int i = st; i < en; i++)
	{
		if (lidx == mid) temp[i] = arr[ridx++];
		else if (ridx == en) temp[i] = arr[lidx++];
		else if (arr[lidx] <= arr[ridx]) temp[i] = arr[lidx++];
		else temp[i] = arr[ridx++];
	}

	for (int i = st; i < en; i++)
		arr[i] = temp[i];
}

void merge_sort(int st, int en)
{
	if (st + 1 == en) return;
	int mid = (st + en) / 2;
	merge_sort(st, mid);
	merge_sort(mid, en);
	merge(st, en);
}


int main()
{
	merge_sort(0, 10);
	for (const int& i : arr)
		cout << i << " ";
	cout << "\n";

	return 0;
}