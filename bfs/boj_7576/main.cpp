// 1. 시작하는 칸을 방문했다는 표시를 남기고 큐에 삽입
// 2. 큐에서 원소를 빼내어 인접한 칸들에 대해 3번을 시행
// 3. 이미 방문했다면 아무것도 하지 않고, 방문하지 않았다면 방문했다는 표시를 남기고 큐에 삽입
// 4. 큐가 빌 때까지 2번 과정을 반복


// 여러 개의 시작점에서 출발, 모든 칸까지의 거리를 구하는 문제

#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int box[1001][1001];
int dist[1001][1001];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int m, n; // m은 열을 의미, n은 행을 의미 (m->y, n->x)
	cin >> m >> n;
	
	for (int i = 0; i < n; i++)
		fill(dist[i], dist[i] + m, 0);

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int tomato;
			cin >> tomato;
			box[i][j] = tomato;

			if (tomato == 1)
			{
				// 초기 토마토가 존재하는 칸의 경우 1
				q.push({ i, j });
				dist[i][j] = 1;
			}
			else if (tomato == -1)
			{
				// 토마토가 존재하지 않은 칸의 경우 -1
				dist[i][j] = -1;
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
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			// 이미 익었거나, 토마토가 존재하지 않는 칸일 경우 아무것도 하지 않고 건너 뜀
			if (dist[nx][ny] != 0 || box[nx][ny] == -1) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx, ny });
		}
	}

	int date = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (date < dist[i][j]) date = dist[i][j];
			if (dist[i][j] == 0)
			{
				// 익지 않은 토마토가 있는 경우 
				cout << -1 << "\n";
				return 0;
			}
		}
	}

	cout << date - 1 << "\n";
	return 0;
}
