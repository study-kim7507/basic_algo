// BOJ 12865. 평범한 배낭
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	// {무게, 가치}
	vector<pair<int, int>> things(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int w, v;
		cin >> w >> v;
		things[i] = { w, v };
	}

	vector<int> dp(k + 1, 0);
	for (int i = 0; i <= k; i++)
	{
		if (things[1].first <= i)
			dp[i] = things[1].second;
	}

	for (int i = 2; i <= n; i++)
		for (int j = k; j >= things[i].first; j--)
			dp[j] = max(dp[j], dp[j - things[i].first] + things[i].second);

	std::cout << dp[k] << "\n";
	return 0;
}