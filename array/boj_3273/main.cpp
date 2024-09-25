#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	sort(arr, arr + n);

	int x;
	cin >> x;

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if (binary_search(arr, arr + n, x - arr[i]))
		{
			count++;
		}
	}

	cout << count / 2 << "\n";
	return 0;
}