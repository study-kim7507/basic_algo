// BOJ_1600. 말이 되고픈 원숭이
#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

#define X first
#define Y second

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

const int dx_h[8] = { -1, -2, -2, -1, 1, 2, 1, 2 };
const int dy_h[8] = { -2, -1, 1, 2, -2, -1, 2, 1 };

int k, w, h;
int board[201][201];
int dist[201][201][31];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> k >> w >> h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> board[i][j];

	queue<pair<pair<int, int>, int>> q;
	q.push({ {0, 0}, 0 });
	dist[0][0][0] = 1;

	while (!q.empty())
	{
		auto front = q.front(); q.pop();

		int cnt = front.Y;
		auto pos = front.X;

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = pos.X + dx[dir];
			int ny = pos.Y + dy[dir];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (dist[nx][ny][cnt] != 0 && dist[nx][ny][cnt] <= dist[pos.X][pos.Y][cnt] + 1) continue;
			if (board[nx][ny] != 0) continue;

			dist[nx][ny][cnt] = dist[pos.X][pos.Y][cnt] + 1;
			q.push({ {nx, ny}, cnt });
		}

		for (int dir = 0; dir < 8; dir++)
		{
			if (cnt >= k) break;

			int nx = pos.X + dx_h[dir];
			int ny = pos.Y + dy_h[dir];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (dist[nx][ny][cnt + 1] != 0 && dist[nx][ny][cnt + 1] <= dist[pos.X][pos.Y][cnt] + 1) continue;
			if (board[nx][ny] != 0) continue;

			dist[nx][ny][cnt + 1] = dist[pos.X][pos.Y][cnt] + 1;
			q.push({ {nx, ny}, cnt + 1 });
		}
	}

	int ans = INT_MAX;
	for (int i = 0; i <= k; i++)
	{
		if (dist[h - 1][w - 1][i] != 0)
			ans = min(ans, dist[h - 1][w - 1][i]);
	}

	if (ans == INT_MAX) std::cout << -1 << "\n";
	else std::cout << ans - 1 << "\n";
	return 0;
}