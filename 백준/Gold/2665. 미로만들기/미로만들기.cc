// BOJ_2665. 미로만들기
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second
#define INF 0x3f3f3f3f

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int board[51][51];
int dist[51][51];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string row;
		cin >> row;
		for (int j = 0; j < n; j++)
			board[i][j] = int(row[j] - '0');
	}

	for (int i = 0; i < n; i++)
		fill(dist[i], dist[i] + n, INF);

	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	dist[0][0] = 0;

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny] == 1)
			{
				if (dist[nx][ny] > dist[cur.X][cur.Y]) dist[nx][ny] = dist[cur.X][cur.Y];
				else continue;
			}
			else if (board[nx][ny] == 0)
			{
				if (dist[nx][ny] > dist[cur.X][cur.Y] + 1) dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				else continue;
			}

			q.push({ nx, ny });
		}
	}

	std::cout << dist[n - 1][n - 1] << "\n";

	return 0;
}