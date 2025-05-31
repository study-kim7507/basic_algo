// BOJ_4811. 알약
#include <iostream>

using namespace std;

long long dp[31][31];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 31; i++)
		dp[0][i] = 1;

	for (int i = 1; i < 31; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			if (j == 0) dp[i][j] = dp[i - 1][1];
			else dp[i][j] = dp[i - 1][j + 1] + dp[i][j - 1];
		}
	}

	while (true)
	{
		int n;
		cin >> n;
		if (n == 0) break;

		std::cout << dp[n - 1][1] << "\n";
	}
	return 0;
}