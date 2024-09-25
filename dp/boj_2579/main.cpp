// dp[i][j] : j개의 계단을 연속해서 밟고 올라온 상황에서, i번째 계단을 밟았을 때 최대값
// dp[i][1] = max(dp[i-2][2], dp[i-2][1]) + s[i]
// dp[i][2] = dp[i-1][1] + s[i]

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[301][3];
int s[301];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i];

	dp[1][1] = s[1];
	dp[1][2] = 0;
	dp[2][1] = s[2];
	dp[2][2] = s[1] + s[2];
	
	for (int i = 3; i <= n; i++)
	{
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + s[i];
		dp[i][2] = dp[i - 1][1] + s[i];
	}

	cout << max(dp[n][1], dp[n][2]) << "\n";

	return 0;
}