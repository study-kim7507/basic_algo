// BOJ_12865. 평범한 배낭
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;

// {무게, 가치}
int weights[101];
int values[101];
// dp[i][w] : 최대 무게가 w인 가방에서 i번째 물건까지 판단했을 때의 최대 가치
int dp[101][100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> weights[i];
		cin >> values[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (weights[i] > j) dp[i][j] = dp[i - 1][j];
			else if (weights[i] <= j) dp[i][j] = max(dp[i - 1][j], values[i] + dp[i - 1][j - weights[i]]);
		}
	}

	std::cout << dp[n][k];
	return 0;
}