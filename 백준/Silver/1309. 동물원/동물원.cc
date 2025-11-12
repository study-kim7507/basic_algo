// BOJ_1309. 동물원
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD 9901

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> dp(n, vector<int>(3, 0));
	dp[0][0] = dp[0][1] = dp[0][2] = 1;

	for (int i = 1; i < n; i++)
	{
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
	}
	
	std::cout << (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]) % MOD << "\n";
	return 0;
}