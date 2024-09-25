#include <iostream>
using namespace std;

int arr[] = { 3, 2, 7, 116, 62, 235, 1, 23, 55, 77 };
int n = 10;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < n; i++)
	{
		int minIdx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[minIdx] > arr[j]) minIdx = j;
		}
		swap(arr[minIdx], arr[i]);
	}

	for (int a : arr)
		cout << a << " ";
	cout << "\n";

	return 0;
}