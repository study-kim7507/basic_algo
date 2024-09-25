#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int map[301][301];
bool visit[301][301];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	int year = 0;
	for (year = 0; ; year++)
	{

		for (int i = 0; i < N; i++)
			fill(visit[i], visit[i] + M, false);


		// 빙산의 개수 파악
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 0 || visit[i][j])
					continue;

				cnt++;
				queue<pair<int, int>> q;
				q.push({ i, j });
				visit[i][j] = true;
				while (!q.empty())
				{
					auto cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
						if (map[nx][ny] == 0 || visit[nx][ny]) continue;
						q.push({ nx, ny });
						visit[nx][ny] = true;
					}
				}
			}
		}

		// 빙산의 개수가 2개 이상이 아니라면 녹이는 과정 수행
		if (cnt >= 2) break;
		else if (cnt == 0)
		{
			// 빙산이 다 녹은 상황
			cout << 0 << "\n";
			return 0;
		}
		for (int i = 0; i < N; i++)
			fill(visit[i], visit[i] + M, false);

		// 빙산을 녹임
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 0 || visit[i][j])
					continue;

				queue<pair<int, int>> q;
				q.push({ i, j });
				visit[i][j] = true;
				while (!q.empty())
				{
					int cnt = 0;
					auto cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
						if (map[nx][ny] == 0 && !visit[nx][ny])
						{
							cnt++;
							continue;
						}
						if (visit[nx][ny] == true) continue;
						q.push({ nx, ny });
						visit[nx][ny] = true;
					}
					map[cur.X][cur.Y] = max(0, map[cur.X][cur.Y] - cnt);
				}
			}
		}

		
	}
	
	cout << year << "\n";
	return 0;
}