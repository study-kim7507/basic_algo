#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
long long arr[1001];
vector<long long> twoSum;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	// 두 수의 합
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			twoSum.push_back(arr[i] + arr[j]);
	
	sort(twoSum.begin(), twoSum.end());

	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (binary_search(twoSum.begin(), twoSum.end(), arr[i] - arr[j]))
			{
				cout << arr[i] << "\n";
				return 0;
			}
		}
	}

	return 0;
}