// 1. 시작하는 칸을 방문 표시 후, 큐에 삽입
// 2. 원소를 큐에서 꺼내서 인접한 칸에 대해 3번을 시행
// 3. 만약 해당 칸이 방문던 칸이면 아무것도 하지 않고, 방문하지 않았다면 방문표시 후 큐에 삽입
// 4. 큐가 빌 때까지 2번을 반복

#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int board[51][51];
bool visit[51][51];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int M, N, K; // M : 열 (M -> y), N : 행 (N -> x)
		cin >> M >> N >> K;

		while (K--)
		{
			int x, y;
			cin >> y >> x;
			board[x][y] = 1;
		}

		int result = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (board[i][j] == 1 && !visit[i][j])
				{
					result++;
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
							if (visit[nx][ny] || board[nx][ny] != 1) continue;
							q.push({ nx, ny });
							visit[nx][ny] = true;
						}
					}
				}
			}
		}

		cout << result << "\n";

		for (int i = 0; i < N; i++)
			fill(board[i], board[i] + M, 0);
		for (int i = 0; i < N; i++)
			fill(visit[i], visit[i] + M, false);
	}

	return 0;
}