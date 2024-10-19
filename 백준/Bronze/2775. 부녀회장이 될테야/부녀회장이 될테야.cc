// dp[i][j] : i층 j호에 살고 있는 사람의 수
// dp[i][j] = dp[i][j-1] + dp[i-1][j]

#include <iostream>
using namespace std;

int dp[15][15];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 0층에는 호의 번호와 동일하게 사람이 거주
	for (int i = 1; i <= 14; i++)
		dp[0][i] = i;

	// 각 층의 1호에는 1명씩 거주
	for (int i = 1; i <= 14; i++)
		dp[i][1] = 1;

	for (int i = 1; i <= 14; i++)
		for (int j = 1; j <= 14; j++)
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
	

	int t;
	cin >> t;
	while (t--)
	{
		int k, n;
		cin >> k >> n;
		cout << dp[k][n] << "\n";
	}

	return 0;
}