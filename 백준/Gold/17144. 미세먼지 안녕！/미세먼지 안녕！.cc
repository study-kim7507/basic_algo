// BOJ_17144. 미세먼지 안녕!
#include <iostream>
#include <queue>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

vector<pair<int, int>> purifier;
int r, c, t;
int board[51][51];

queue<pair<int, int>> findDust()
{
	queue<pair<int, int>> result;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (board[i][j] != 0 && board[i][j] != -1) result.push({ i, j });

	return result;
}

// 확산
void dfs()
{
	queue<pair<int, int>> curDust = findDust();

	int tempBoard[51][51];
	for (int i = 0; i < r; i++)
		fill(tempBoard[i], tempBoard[i] + c, 0);

	while (!curDust.empty())
	{
		auto cur = curDust.front(); curDust.pop();

		int cnt = 0;
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (board[nx][ny] == -1) continue;

			tempBoard[nx][ny] += board[cur.X][cur.Y] / 5;
			cnt++;
		}

		board[cur.X][cur.Y] -= (board[cur.X][cur.Y] / 5 * cnt);
	}

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (tempBoard[i][j] != -1 && tempBoard[i][j] != 0)
				board[i][j] += tempBoard[i][j];
}

// 회전
void rotate()
{
	int tempBoard[51][51];
	for (int i = 0; i < r; i++)
		fill(tempBoard[i], tempBoard[i] + c, 0);

	// 윗방향
	pair<int, int> upPurifier = purifier[0];
	for (int i = 1; i < c; i++) tempBoard[0][i - 1] = board[0][i];								// 첫 행
	for (int i = 0; i < upPurifier.X; i++) tempBoard[i + 1][0] = board[i][0];					// 첫 열
	for (int i = 1; i < c - 1; i++) tempBoard[upPurifier.X][i + 1] = board[upPurifier.X][i];	// 마지막 행
	for (int i = upPurifier.X; i > 0; i--) tempBoard[i - 1][c - 1] = board[i][c - 1];			// 마지막 열

	// 아랫방향
	pair<int, int> downPurifier = purifier[1];
	for (int i = 1; i < c - 1; i++) tempBoard[downPurifier.X][i + 1] = board[downPurifier.X][i];	// 첫 행
	for (int i = r - 1; i > downPurifier.X; i--) tempBoard[i - 1][0] = board[i][0];								// 첫 열
	for (int i = c - 1; i > 0; i--) tempBoard[r - 1][i - 1] = board[r - 1][i];						// 마지막 행
	for (int i = downPurifier.X; i < r - 1; i++) tempBoard[i + 1][c - 1] = board[i][c - 1];			// 마지막 열

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (i == 0 || i == upPurifier.X || i == downPurifier.X || i == r - 1 || j == 0 || j == c - 1)
				board[i][j] = tempBoard[i][j];
	for (auto e : purifier)
		board[e.X][e.Y] = -1;
}

void forDebugging()
{
	std::cout << "\n";
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			std::cout << board[i][j] << " ";
		}
		std::cout << "\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> r >> c >> t;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == -1) purifier.push_back({ i,j });
		}
	}

	for (int i = 0; i < t; i++)
	{
		dfs();
		rotate();
	}

	int answer = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (board[i][j] != -1) answer += board[i][j];

	std::cout << answer << "\n";
	//forDebugging();

	return 0;
}