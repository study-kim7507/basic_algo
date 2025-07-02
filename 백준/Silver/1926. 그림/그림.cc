// BOJ_1926. 그림
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n, m;
int board[501][501];
bool vis[501][501];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	int cnt = 0;
	int area = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (vis[i][j] || board[i][j] == 0) continue;

			cnt++;

			queue<pair<int, int>> q;
			q.push({ i, j });
			vis[i][j] = true;

			int curArea = 0;
			while (!q.empty())
			{
				auto cur = q.front(); q.pop();
				curArea++;
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (board[nx][ny] == 0) continue;
					if (vis[nx][ny]) continue;

					q.push({ nx, ny });
					vis[nx][ny] = true;
				}
			}

			area = max(area, curArea);
		}
	}

	std::cout << cnt << "\n" << area << "\n";

	return 0;
}