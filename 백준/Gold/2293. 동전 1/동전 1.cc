// BOJ_2293. 동전 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n, k;
vector<int> coins;

int dp[10001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int coin;
		cin >> coin;
		coins.push_back(coin);
	}

	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = coins[i]; j <= k; j++)
		{
			dp[j] += dp[j - coins[i]];
		}
	}
	std::cout << dp[k] << "\n";

	return 0;
}