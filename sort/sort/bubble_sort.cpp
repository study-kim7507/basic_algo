#include <iostream>
using namespace std;


int arr[] = { 3, 2, 7, 116, 62, 235, 1, 23, 55, 77 };
int n = 10;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j <= i + 1; j++)
		{
			if (arr[j] > arr[i]) swap(arr[i], arr[j]);
		}
	}

	for (int i : arr)
		cout << i << " ";
	cout << "\n";
	return 0;
}