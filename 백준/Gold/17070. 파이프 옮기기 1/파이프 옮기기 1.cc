// BOJ_17070. 파이프 옮기기 1
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int answer = 0;

// 집, 파이프 한쪽 끝 좌표, 방향 (0 : 가로, 1 : 세로, 2 : 대각선)
void dfs(vector<vector<int>>& board, int r, int c, int direction)
{
	if (r <= 0 || r > n || c <= 0 || c > n) return;
	if (r == n && c == n)
	{
		answer++;
		return;
	}

	// 가로인 경우
	if (direction == 0)
	{
		// 오른쪽 이동
		if (c < n && board[r][c + 1] == 0) dfs(board, r, c + 1, 0);
		
		// 대각선 이동
		if (r < n && c < n &&
			board[r][c + 1] == 0 &&
			board[r + 1][c] == 0 &&
			board[r + 1][c + 1] == 0) dfs(board, r + 1, c + 1, 2);
	}
	// 세로인 경우
	else if (direction == 1)
	{
		// 아래 이동
		if (r < n && board[r + 1][c] == 0) dfs(board, r + 1, c, 1);

		// 대각선 이동
		if (r < n && c < n &&
			board[r][c + 1] == 0 &&
			board[r + 1][c] == 0 &&
			board[r + 1][c + 1] == 0) dfs(board, r + 1, c + 1, 2);
	}

	// 대각선인 경우
	else if (direction == 2)
	{
		// 오른쪽 이동
		if (c < n && board[r][c + 1] == 0) dfs(board, r, c + 1, 0);

		// 아래 이동
		if (r < n && board[r + 1][c] == 0) dfs(board, r + 1, c, 1);

		// 대각선 이동
		if (r < n && c < n &&
			board[r][c + 1] == 0 &&
			board[r + 1][c] == 0 &&
			board[r + 1][c + 1] == 0) dfs(board, r + 1, c + 1, 2);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	vector<vector<int>> board(n + 1, vector<int>(n + 1, 0));;
	for (int r = 1; r <= n; r++)
		for (int c = 1; c <= n; c++)
			cin >> board[r][c];


	dfs(board, 1, 2, 0);
	std::cout << answer << "\n";

	return 0;
}