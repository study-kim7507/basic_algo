#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int board[101][101];
bool visit[101][101];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 5, 7
	int M, N, K; // board[M][N]
	cin >> M >> N >> K;
	while (K--)
	{
		int x1, x2, y1, y2;
		cin >> y1 >> x1 >> y2 >> x2;

		x1 = M - x1;
		x2 = M - x2;
		for (int i = x2; i < x1; i++)
		{
			for (int j = y1; j < y2; j++)
			{
				board[i][j] = 1;
			}
		}
	}
	vector<int> result;

	for (int x = 0; x < M; x++)
	{
		for (int y = 0; y < N; y++)
		{
			if (board[x][y] == 0 && visit[x][y] == false)
			{
				int area = 0;
				queue<pair<int, int>> q;
				q.push({ x, y });
				visit[x][y] = true;

				while (!q.empty())
				{
					area++;
					auto cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
						if (board[nx][ny] != 0 || visit[nx][ny] == true) continue;
						q.push({ nx, ny });
						visit[nx][ny] = true;
					}
				}

				result.push_back(area);
			}
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (int a : result)
	{
		cout << a << " ";
	}


	return 0;
}