#include <iostream>
#include <algorithm>
using namespace std;

int n;
int tri[501][501];
int dp[501][501];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			cin >> tri[i][j];
	}

	dp[0][0] = tri[0][0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0) dp[i][j] = dp[i - 1][j] + tri[i][j];
			else if (j == i) dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
			else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans = max(dp[n - 1][i], ans);
	}
	
	cout << ans << "\n";
	return 0;
}