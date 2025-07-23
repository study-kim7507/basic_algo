// BOJ_15486. 퇴사 2
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1500001];
pair<int, int> arr[1500001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int t, p;
		cin >> t >> p;
		arr[i] = { t, p };
	}

	for (int i = 1; i <= n; i++)
	{
		int t = arr[i].first;
		int p = arr[i].second;

		if (i + t <= n + 1) dp[i + t] = max(dp[i + t], dp[i] + p);
		dp[i + 1] = max(dp[i], dp[i + 1]);
	}

	std::cout << dp[n + 1] << "\n";
	return 0;
}