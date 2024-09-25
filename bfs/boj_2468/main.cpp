// 최소 비의 양(비가 아예 내리지 않을 수 있음), 최대 비의 양까지 모두 bfs를 돌며 영역의 개수를 카운트
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int board[101][101];
bool visit[101][101];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	// 내릴 수 있는 비의 최대량
	int max = -1;

	for (int i = 0; i < N; i++)
	{
		if (max < *max_element(board[i], board[i] + N))
			max = *max_element(board[i], board[i] + N);
	}

	// 내릴 수 있는 비의 최소량부터 최대량까지 순회하며 bfs
	// 비가 아예 내리지 않을 수도 있음을 고려해야함
	// 영역의 최대 갯수 찾기
	int ans = 0;
	for (int i = 0; i <= max; i++)
	{
		int area = 0;
		for (int a = 0; a < N; a++)
		{
			for (int b = 0; b < N; b++)
			{
				if (board[a][b] > i && !visit[a][b])
				{
					area++;
					queue<pair<int, int>> q;
					q.push({ a, b });
					visit[a][b] = true;
					while (!q.empty())
					{
						auto cur = q.front(); q.pop();
						for (int dir = 0; dir < 4; dir++)
						{
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
							if (visit[nx][ny] || board[nx][ny] <= i) continue;
							q.push({ nx, ny });
							visit[nx][ny] = true;
						}
					}
				}
			}
		}
		if (ans < area) ans = area;
		for (int k = 0; k < N; k++)
			fill(visit[k], visit[k] + N, false);
	}
	cout << ans << "\n";
	return 0;
}