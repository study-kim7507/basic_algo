// BOJ 1520. 내리막 길
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

#define X first
#define Y second

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int m, n;
vector<vector<int>> board;
vector<vector<int>> dp;

int dfs(pair<int, int> curPos)
{
	if (curPos == make_pair(m - 1, n - 1))
		return 1;
	if (dp[curPos.X][curPos.Y] != -1) return dp[curPos.X][curPos.Y];

	dp[curPos.X][curPos.Y] = 0;
	for (int dir = 0; dir < 4; dir++)
	{
		int nx = curPos.X + dx[dir];
		int ny = curPos.Y + dy[dir];

		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		if (board[nx][ny] >= board[curPos.X][curPos.Y]) continue;
		
		dp[curPos.X][curPos.Y] += dfs(make_pair(nx, ny));
	}

	return dp[curPos.X][curPos.Y];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> m >> n;

	board = vector<vector<int>>(m, vector<int>(n, 0));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	dp = vector<vector<int>>(m, vector<int>(n, -1));
	std::cout << dfs(make_pair(0, 0)) << "\n";
	return 0;
}