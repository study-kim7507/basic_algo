// 이항계수의 성질 이용 -> DP
// nCk = n-1Ck + n-1Ck-1
#include <iostream>
using namespace std;

int dp[1001][1001];			// dp[n][k] = nCk

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= 1000; i++)
	{
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; j++)
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
	}
	cout << dp[n][k] << "\n";

	return 0;
}