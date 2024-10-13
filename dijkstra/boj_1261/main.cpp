#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int n, m;
int board[101][101];
int d[101][101];
const int INF = 0x3f3f3f3f;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> m >> n;
	for (int i = 1; i <= n; i++)
	{
		string input;
		cin >> input;
		for (int j = 1; j <= m; j++)
			board[i][j] = int(input[j - 1] - '0');
		fill(d[i], d[i] + m + 1, INF);
	}

	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	d[1][1] = 0;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;

			if (board[nx][ny] == 1)
			{
				if (d[nx][ny] > d[cur.X][cur.Y] + 1)
				{
					d[nx][ny] = d[cur.X][cur.Y] + 1;
					q.push({ nx, ny });
				}
			}
			if (board[nx][ny] == 0)
			{
				if (d[nx][ny] > d[cur.X][cur.Y])
				{
					d[nx][ny] = d[cur.X][cur.Y];
					q.push({ nx, ny });
				}
			}
		}
	}


	cout << d[n][m] << "\n";
	return 0;
}