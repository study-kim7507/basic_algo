// BOJ 14940. 쉬운 최단거리
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> board(n, vector<int>(m));
	vector<vector<int>> dist(n, vector<int>(m, -1));
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
			{
				q.push({ i, j });
				dist[i][j] = 0;
			}
		}
	}

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 0) continue;
			if (dist[nx][ny] != -1 && dist[nx][ny] <= dist[cur.X][cur.Y] + 1) continue;

			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx, ny });
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dist[i][j] == -1)
			{
				if (board[i][j] == 0) std::cout << 0 << " ";
				else std::cout << -1 << " ";
			}
			else std::cout << dist[i][j] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}