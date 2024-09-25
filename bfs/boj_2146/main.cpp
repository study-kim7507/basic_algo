// 육지에서 시작 -> 바다를 만나면 다리 공사 시작 -> 바다만을 따라가다 -> 육지를 만나면 값 비교

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int map[101][101];
int visit[101][101];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int ans = 987654321;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}


	// 인접한 칸은 동일한 섬으로 묶음
	int num = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[i][j] == 1 || map[i][j] == 0) continue;

			queue<pair<int, int>> q;
			q.push({ i, j });
			visit[i][j] = 1;

			while (!q.empty())
			{
				auto cur = q.front(); q.pop();
				map[cur.X][cur.Y] = num;
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (map[nx][ny] == 0 || visit[nx][ny] == 1) continue;
					q.push({ nx, ny });
					visit[nx][ny] = 1;
				}
			}
			num++;
		}
	}

	for (int i = 0; i < n; i++)
		fill(visit[i], visit[i] + n, 0);

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] != 0)
			{
				q.push({ i, j });
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
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (map[nx][ny] == map[cur.X][cur.Y]) continue; // 같은 섬인 경우
			if (map[nx][ny] != 0) // 다른 섬인 경우
			{
				ans = min(ans, visit[nx][ny] + visit[cur.X][cur.Y]);
			}
			else if (map[nx][ny] == 0) // 바다인 경우
			{
				map[nx][ny] = map[cur.X][cur.Y];
				visit[nx][ny] = visit[cur.X][cur.Y] + 1;
				q.push({ nx, ny });
			}
		}
	}

	cout << ans << "\n";

	return 0;
}