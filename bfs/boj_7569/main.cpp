#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

#define X(t) get<0>(t)
#define Y(t) get<1>(t)
#define Z(t) get<2>(t)

int box[101][101][101];
int visit[101][101][101];

int dx[6] = { 0, 1, 0, -1, 0, 0 };
int dy[6] = { 1, 0, -1, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int M, N, H; // box[N][M][H];
	cin >> M >> N >> H;
	
	bool isAlready = true;
	queue<tuple<int, int, int>> q;
	for (int z = 0; z < H; z++)
	{
		for (int x = 0; x < N; x++)
		{
			for (int y = 0; y < M; y++)
			{
				cin >> box[x][y][z];
				// 토마토가 들어있는 박스라면
				if (box[x][y][z] == 1)
				{
					q.push({ x, y, z });
					visit[x][y][z] = 1;
				}
				// 토마토가 들어있지 않은 박스라면
				else if (box[x][y][z] == -1)
				{
					visit[x][y][z] = -1;
				}
				// 박스에 존재하는 모든 토마토가 이미 익어있는지 판단
				else if (box[x][y][z] == 0)
				{
					isAlready = false;
				}
			}
		}
	}

	// 이미 모든 토마토가 익어있는 경우
	if (isAlready)
	{
		cout << 0 << "\n";
		return 0;
	}

	int max = 0;

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 6; dir++)
		{
			int nx = X(cur) + dx[dir];
			int ny = Y(cur) + dy[dir];
			int nz = Z(cur) + dz[dir];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) continue;
			if (visit[nx][ny][nz] > 0 || box[nx][ny][nz] == -1) continue;
			visit[nx][ny][nz] = visit[X(cur)][Y(cur)][Z(cur)] + 1;
			q.push({ nx, ny, nz });
			if (max < visit[nx][ny][nz]) max = visit[nx][ny][nz];
		}
	}
	
	for (int z = 0; z < H; z++)
	{
		for (int x = 0; x < N; x++)
		{
			for (int y = 0; y < M; y++)
			{
				// 토마토가 들어있지만, 익지 않은 경우
				if (box[x][y][z] == 0 && visit[x][y][z] == 0)
				{
					cout << -1 << "\n";
					return 0;
				}
			}
		}
	}

	cout << max - 1 << "\n";
	return 0;
}