// BOJ 17404. RGB 거리 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f

int n;
int cost[1001][3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int r, g, b;
		cin >> r >> g >> b;
		cost[i][0] = r; cost[i][1] = g; cost[i][2] = b;
	}

	int ans = INF;
	for (int i = 0; i < 3; i++)
	{
		int dp[1001][3];
		dp[1][0] = dp[1][1] = dp[1][2] = INF;
		dp[1][i] = cost[1][i];

		for (int j = 2; j <= n; j++)
		{
			dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + cost[j][0];
			dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + cost[j][1];
			dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + cost[j][2];
		}

		for (int j = 0; j < 3; j++)
		{
			if (i == j) continue;
			ans = min(ans, dp[n][j]);
		}
	}

	std::cout << ans << "\n";

	return 0;
}