#include <iostream>
#include <algorithm>
using namespace std;

int inputs[1001];
int dp[1001][31];				// dp[i][j] : i초까지 수행했을 때, 자두의 이동 횟수 j이고 이 때 얻은 최대 자두의 개수

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t, w;
	cin >> t >> w;
	for (int i = 1; i <= t; i++)
		cin >> inputs[i];

	// 2 1 1 2 2 1 1
	
	if (inputs[1] == 1)
		dp[1][0] = 1;
	else if (inputs[1] == 2)
		dp[1][1] = 1;

	for (int i = 2; i <= t; i++)
	{
		for (int j = 0; j <= w; j++)
		{
			if (inputs[i] == 1)
			{
				if (j == 0) dp[i][j] = dp[i - 1][j] + 1;
				else if (j % 2 == 1) dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
				else if (j % 2 == 0) dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + 1;
			}
			else if (inputs[i] == 2)
			{
				if (j == 0) dp[i][j] = dp[i - 1][j];
				else if (j % 2 == 1) dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + 1;
				else if (j % 2 == 0) dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
		}
	}

	int ans = -987654321;
	for (int i = 1; i <= t; i++)
		for (int j = 0; j <= w; j++)
			ans = max(ans, dp[i][j]);

	cout << ans << "\n";
	return 0;
}