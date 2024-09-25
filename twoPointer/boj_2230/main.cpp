// 이분 탐색 풀이
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

int n, m;
long long arr[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];


	sort(arr, arr + n);

	long long ans = numeric_limits<long long>::max();
	for (int i = 0; i < n - 1; i++)
	{
		long long target = arr[i] + m;
		long long result = arr[lower_bound(arr, arr + n, target) - arr] - arr[i];
		if (result >= m && result < ans) ans = result;
	}

	cout << ans;
	return 0;
}