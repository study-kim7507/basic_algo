// BOJ 1890. 점프
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	long long dp[101][101];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int dist = board[i][j];
			if (dist == 0) continue;

			if (i + dist < n) dp[i + dist][j] += dp[i][j];
			if (j + dist < n) dp[i][j + dist] += dp[i][j];
			
		}
	}


	std::cout << dp[n - 1][n - 1] << "\n";

	return 0;
}