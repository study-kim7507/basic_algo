#include <iostream>
#include <algorithm>
using namespace std;

int n;

// dp[i][j] = i번째 집을 j색으로 칠했을 때 드는 최소비용의 합
int dp[1001][3];
int cost[1001][3];


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> cost[i][j];
	}

	dp[1][0] = cost[1][0];
	dp[1][1] = cost[1][1];
	dp[1][2] = cost[1][2];
	// dp[2][0] = min(dp[1][1], dp[1][2]) + cost[2][0];
	// dp[2][1] = min(dp[1][0], dp[1][2]) + cost[2][1];
	// dp[2][2] = min(dp[1][0], dp[1][1]) + cost[2][2];

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}

	cout << min({ dp[n][0], dp[n][1], dp[n][2] }) << "\n";

	return 0;
}