// 투포인터 풀이
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

int n, m;
long long arr[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	long long ans = numeric_limits<long long>::max();

	// 투 포인터
	int en = 0;
	for (int st = 0; st < n; st++)
	{
		while (en < n && arr[en] - arr[st] < m) en++;
		if (en == n) break;
		ans = min(ans, arr[en] - arr[st]);
	}
	cout << ans << "\n";
	return 0;
}