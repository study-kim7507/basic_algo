// 3차원 bfs
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

#define X(t) get<0>(t)
#define Y(t) get<1>(t)
#define Z(t) get<2>(t)


char building[31][31][31];
int visit[31][31][31];

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0,0, 0, 0, 1, -1 };

int main()
{
	while (true)
	{
		int L, R, C;
		cin >> L >> R >> C; // building[R][C][L]
		if (L == 0 && R == 0 && C == 0) break;

		queue<tuple<int, int, int>> q;
		for (int z = 0; z < L; z++)
		{
			for (int x = 0; x < R; x++)
			{
				string str;
				cin >> str;
				for (int y = 0; y < str.size(); y++)
				{
					building[x][y][z] = str[y];
					if (building[x][y][z] == 'S')
					{
						q.push({ x, y, z });
						visit[x][y][z] = 1;
					}
				}
			}
		}

		bool can = false;
		while (!q.empty() && !can)
		{
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 6; dir++)
			{
				int nx = X(cur) + dx[dir];
				int ny = Y(cur) + dy[dir];
				int nz = Z(cur) + dz[dir];
				if (nx < 0 || ny < 0 || nz < 0) continue;
				if (nx >= R || ny >= C || nz >= L) continue;
				if (building[nx][ny][nz] == 'E')
				{
					can = true;
					cout << "Escaped in " << visit[X(cur)][Y(cur)][Z(cur)] << " minute(s)." << "\n";
					break;
				}
				if (visit[nx][ny][nz] != 0 || building[nx][ny][nz] == '#') continue;
				visit[nx][ny][nz] = visit[X(cur)][Y(cur)][Z(cur)] + 1;
				q.push({ nx, ny, nz });
			}
		}
		
		if (!can)
			cout << "Trapped!" << "\n";

		// 초기화
		for (int x = 0; x < R; x++)
		{
			for (int y = 0; y < C; y++)
			{
				fill(building[x][y], building[x][y] + L, ' ');
				fill(visit[x][y], visit[x][y] + L, 0);
			}
		}
	}
	
	
	return 0;
}