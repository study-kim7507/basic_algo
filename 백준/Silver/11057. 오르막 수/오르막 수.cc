// BOJ 11057. 오르막수
// dp[i][j] : i자리 수 오르막수 중 j로 시작하는 오르막수의 개수
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define DIV 10007

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = j; k < 10; k++)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % DIV;
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < 10; i++)
		ans = (ans + dp[n][i]) % DIV;

	std::cout << ans << "\n";
	return 0;
}