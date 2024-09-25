// 1. 시작하는 칸을 방문 표시를 하고, 큐에 삽입
// 2. 큐에서 원소를 빼내어 인접한 칸에 대해 3번의 과정을 반복
// 3. 이미 방문했다면 아무 것도 하지 않고, 방문하지 않았다면 방문했다는 표시를 남기고 큐에 삽입
// 4. 큐가 빌 때까지 2번의 과정을 반복

#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int maze[101][101];
int visit[101][101]; // 방문 표시를 위한 다차원배열에 시작 지점에서 해당 지점까지의 최소거리를 저장

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; // n은 행, m은 열 (n->x, m->y)
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++)
		{
			maze[i][j] = int(str[j - 1] - '0');
		}
	}

	queue<pair<int, int>> q;
	visit[1][1] = 1;
	q.push({ 1, 1 });

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
			if (visit[nx][ny] != 0 || maze[nx][ny] != 1) continue;
			q.push({ nx, ny });
			visit[nx][ny] = visit[cur.X][cur.Y] + 1;
		}
	}

	cout << visit[n][m] << "\n";
	return 0;
}