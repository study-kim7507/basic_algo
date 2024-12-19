// 4179. 불!
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

char board[1001][1001];
int vis_jihoon[1001][1001];
int vis_fire[1001][1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int r, c;
	cin >> r >> c;

	queue<pair<int, int>> q_jihoon;
	queue<pair<int, int>> q_fire;

	// 미로 입력
	for (int i = 0; i < r; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < c; j++)
		{
			board[i][j] = input[j];
			
			if (board[i][j] == 'J')
			{
				q_jihoon.push({ i, j });
				vis_jihoon[i][j] = 1;
			}

			else if (board[i][j] == 'F')
			{
				q_fire.push({ i, j });
				vis_fire[i][j] = 1;
			}
		}
	}

	// 불 전파
	while (!q_fire.empty())
	{
		auto cur = q_fire.front(); q_fire.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (vis_fire[nx][ny] != 0 || board[nx][ny] == '#') continue;
			vis_fire[nx][ny] = vis_fire[cur.X][cur.Y] + 1;
			q_fire.push({ nx, ny });
		}
	}

	// 지훈 이동
	while (!q_jihoon.empty())
	{
		auto cur = q_jihoon.front(); q_jihoon.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			// 탈출 성공
			if (nx < 0 || ny < 0 || nx >= r || ny >= c)
			{
				cout << vis_jihoon[cur.X][cur.Y] << "\n";
				return 0;
			}

			if (vis_jihoon[nx][ny] != 0 || board[nx][ny] == '#' || board[nx][ny] == 'F') continue;
			if (vis_jihoon[cur.X][cur.Y] + 1 >= vis_fire[nx][ny] && (vis_fire[nx][ny] != 0)) continue;
			vis_jihoon[nx][ny] = vis_jihoon[cur.X][cur.Y] + 1;
			q_jihoon.push({ nx, ny });
		}
	}


	cout << "IMPOSSIBLE" << "\n";
	return 0;
}

