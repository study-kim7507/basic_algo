// BOJ_17070. 파이프 옮기기 1
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int board[17][17];

// 0: 가로, 1: 세로, 2: 대각선
int dp[3][17][17];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];

	// 초기값 설정
	dp[0][1][2] = 1;
	for (int i = 3; i <= n; i++)
	{
		if (board[1][i] == 0)
			dp[0][1][i] = dp[0][1][i - 1];
	}
		
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			// 대각선
			if (board[i][j] == 0 && board[i - 1][j] == 0 && board[i][j - 1] == 0)
			{
				dp[2][i][j] += (dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1]);
			}
			// 가로 및 세로
			if (board[i][j] == 0)
			{
				// 가로
				dp[0][i][j] += (dp[0][i][j - 1] + dp[2][i][j - 1]);

				// 세로
				dp[1][i][j] += (dp[1][i - 1][j] + dp[2][i - 1][j]);
			}
		}
	}

	int answer = 0;
	answer += (dp[0][n][n] + dp[1][n][n] + dp[2][n][n]);
	std::cout << answer << "\n";

	return 0;
}