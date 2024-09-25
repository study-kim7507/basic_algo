// 1. 시작하는 칸을 방문했다는 표시를 남기고 큐에 삽입
// 2. 큐에서 원소를 빼내어 인접한 칸들에 대해 3번을 시행
// 3. 이미 방문했다면 아무것도 하지 않고, 방문하지 않았다면 방문했다는 표시를 남기고 큐에 삽입
// 4. 큐가 빌 때까지 2번 과정을 반복

#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

char board[1001][1001];
int jihoon_dist[1001][1001];
int fire_dist[1001][1001];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int R, C; // R은 행의 개수, C는 열의 개수 (R->x, C->y)
	cin >> R >> C;

	for (int i = 0; i < R; i++)
		fill(jihoon_dist[i], jihoon_dist[i] + C, -1);

	for (int i = 0; i < R; i++)
		fill(fire_dist[i], fire_dist[i] + C, -1);


	queue<pair<int, int>> fire_q;
	queue<pair<int, int>> jihoon_q;
	for (int i = 0; i < R; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < C; j++)
		{
			board[i][j] = str[j];
			if (str[j] == 'F')
			{
				fire_dist[i][j] = 0;
				fire_q.push({ i, j });
			}
			else if (str[j] == 'J')
			{
				jihoon_dist[i][j] = 0;
				jihoon_q.push({ i, j });
			}
		}
	}

	while (!fire_q.empty())
	{
		auto cur = fire_q.front(); fire_q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || ny < 0 || nx > R || ny > C) continue;
			if (fire_dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			fire_dist[nx][ny] = fire_dist[cur.X][cur.Y] + 1;
			fire_q.push({ nx, ny });
		}
	}
	
	while (!jihoon_q.empty())
	{
		auto cur = jihoon_q.front(); jihoon_q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			// 큐에는 거리 순으로 저장됨.
			// 범위를 벗어났음은 탈출에 성공했음을 의미
			if (nx < 0 || ny < 0 || nx >= R || ny >= C)
			{
				cout << jihoon_dist[cur.X][cur.Y] + 1;
				return 0;
			}
			if (jihoon_dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			if (fire_dist[nx][ny] != -1 && jihoon_dist[cur.X][cur.Y] + 1 >= fire_dist[nx][ny]) continue;
			jihoon_dist[nx][ny] = jihoon_dist[cur.X][cur.Y] + 1;
			jihoon_q.push({ nx, ny });
		}
	}

	cout << "IMPOSSIBLE" << "\n";
	return 0;
}