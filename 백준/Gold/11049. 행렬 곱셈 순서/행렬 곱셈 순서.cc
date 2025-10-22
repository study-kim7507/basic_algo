// BOJ 11049. 행렬 곱셈 순서
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	vector<pair<int, int>> matrix(n + 1, pair<int, int>());
	for (int i = 1; i <= n; i++)
	{
		int r, c;
		cin >> r >> c;
		matrix[i] = { r, c };
	}

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
	for (int i = 1; i <= n; i++)
		dp[i][i] = 0;

	for (int diff = 1; diff <= n - 1; diff++)
	{
		for (int i = 1; i <= n - diff; i++)
		{
			for (int k = i; k < i + diff; k++)
			{
				dp[i][i + diff] = min(dp[i][i + diff], dp[i][k] + dp[k + 1][i + diff] + matrix[i].first * matrix[k].second * matrix[i + diff].second);
			}
		}
	}
		
	
	std::cout << dp[1][n] << "\n";
	return 0;
}