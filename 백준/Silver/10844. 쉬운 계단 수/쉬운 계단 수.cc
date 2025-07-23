// BOJ_10844. 쉬운 계단 수
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[101][10];	// dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1]

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++) 
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][1] % 1000000000;
		dp[i][9] = dp[i - 1][8] % 1000000000;
		for (int j = 1; j <= 8; j++) dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
	}

	long long sum = 0;
	for (int i = 0; i <= 9; i++)
		sum += dp[n][i];
	std::cout << sum % 1000000000 << "\n";

	return 0;
}