// BOJ 17404. RGB거리 2
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int cost[1001][3];
	for (int i = 1; i <= n; i++)
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

	int ans = INF;

	// 1번 집의 색상을 미리 결정
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