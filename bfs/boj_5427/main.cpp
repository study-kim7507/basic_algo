// 불이 옮겨진칸, 이제 불이 붙으려는 칸으로는 이동할 수 없음.
// 불의 각 칸으로의 이동 거리, 상근이의 각 칸으로의 이동 거리 측정
// 특정 칸에서의 불과 상근이의 이동 거리를 비교
	// 불의 이동 거리가 상근이의 이동 거리보다 작은 경우 -> 상근이는 해당 칸으로 이동 불가
	// 불의 이동 거리가 상근이의 이동 거리보다 -1 만큼 작은 경우 -> 해당 칸은 이제 곧 불이 붙으려는 칸 -> 상근이는 해당 칸으로 이동 불가

#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

char board[1001][1001];  
int dist[1001][1001]; // 상근이의 이동 거리
int dist_fire[1001][1001]; // 불의 이동 거리

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int w, h; // board[h][w]
		cin >> w >> h;
	
		// 매 테스트 케이스마다 배열 초기화
		for (int i = 0; i < 1001; i++)
		{
			fill(board[i], board[i] + 1001, ' ');
			fill(dist[i], dist[i] + 1001, -1);
			fill(dist_fire[i], dist_fire[i] + 1001, -1);
		}


		queue<pair<int, int>> q;
		queue<pair<int, int>> q_fire;

		for (int x = 0; x < h; x++)
		{
			string str;
			cin >> str;
			for (int y = 0; y < str.size(); y++)
			{
				board[x][y] = str[y];
				// 상근이의 시작점
				if (board[x][y] == '@')
				{
					dist[x][y] = 0;
					q.push({ x, y });
				}
				// 불의 시작점
				else if (board[x][y] == '*')
				{
					dist_fire[x][y] = 0;
					q_fire.push({ x, y });
				}
			}
		}

		// 불의 이동
		while (!q_fire.empty())
		{
			auto cur = q_fire.front(); q_fire.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (dist_fire[nx][ny] != -1 || board[nx][ny] == '#') continue;
				q_fire.push({ nx, ny });
				dist_fire[nx][ny] = dist_fire[cur.X][cur.Y] + 1;
			}
		}

		bool can = false;
		// 상근이의 이동
		while (!q.empty() && can == false)
		{
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w)
				{
					cout << dist[cur.X][cur.Y] + 1 << "\n";
					can = true;
					break;
				}
				if (dist[nx][ny] != -1 || board[nx][ny] == '#' || (dist_fire[nx][ny] != -1 && dist[cur.X][cur.Y] + 1 >= dist_fire[nx][ny]) ||(dist_fire[nx][ny] != -1 && dist[cur.X][cur.Y] - 1 == dist_fire[nx][ny])) continue;
				q.push({ nx, ny });
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			}
		}

		if (!can)
			cout << "IMPOSSIBLE" << "\n";

	}
	return 0;
}