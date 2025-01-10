// 1245. 농장 관리

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

const int dx[8] = { 0, 1, 0, -1, -1, 1, -1, 1};
const int dy[8] = { 1, 0, -1, 0, 1, -1, -1, 1};

int board[101][71];
bool vis[101][71];

int result;

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (vis[i][j]) continue;

			bool isTop = true;

			queue<pair<int, int>> q;
			q.push({ i, j });
			vis[i][j] = true;

			while (!q.empty())
			{
				auto cur = q.front(); q.pop();
				for (int dir = 0; dir < 8; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx > n || ny < 0 || ny > m) continue;
					if (board[nx][ny] > board[cur.X][cur.Y])
					{
						isTop = false;
						continue;
					}
					if (board[nx][ny] < board[cur.X][cur.Y]) continue;
					if (vis[nx][ny]) continue;

					vis[nx][ny] = true;
					q.push({ nx, ny });
				}
			}

			if (isTop) 
				result++;
		}
	}

	cout << result << "\n";

	return 0;
}