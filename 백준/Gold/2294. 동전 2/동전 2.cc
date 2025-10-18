// BOJ 2294. 동전 2
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	set<int> coins;
	for (int i = 0; i < n; i++)
	{
		int coin;
		cin >> coin;
		if (coin > k) continue;
		coins.insert(coin);
	}

	vector<int> dp(k + 1, 0);
	for (int i = 1; i <= k; i++)
	{
		if (coins.find(i) != coins.end()) dp[i] = 1;
		else
		{
			int temp = k;
			for (auto it = coins.begin(); it != coins.end(); it++)
			{
				if (i - *it < 0) continue;
				temp = min(temp, dp[i - *it]);
			}
				
			dp[i] = temp + 1;
		}
	}
	if (dp[k] == k + 1) std::cout << -1 << "\n";
	else std::cout << dp[k] << "\n";
	return 0;
}