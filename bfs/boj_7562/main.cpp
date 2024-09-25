#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int dist[301][301];

int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i;
		cin >> i;

		for (int a = 0; a < i; a++)
			fill(dist[a], dist[a] + i, 0);

		int startX, startY;
		cin >> startX >> startY;

		int endX, endY;
		cin >> endX >> endY;
		dist[endX][endY] = -1;


		if (startX == endX && startY == endY)
		{
			cout << 0 << "\n";
			continue;
		}

		queue<pair<int, int>> q;
		q.push({ startX, startY });

		while (dist[endX][endY] == -1)
		{
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 8; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= i || ny >= i) continue;
				if (dist[nx][ny] > 0) continue;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				q.push({ nx, ny });
			}
		}
		cout << dist[endX][endY] << "\n";
	}

	return 0;
}