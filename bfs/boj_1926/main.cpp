// 1. 시작하는 칸을 방문했다는 표시를 남기고 큐에 삽입
// 2. 큐에서 원소를 빼내어 해당 칸을 인접하는 칸들에 대해 3번을 반복
// 3. 이미 해당 칸을 방문했다면 아무것도 하지 않고, 방문하지 않았다면 방문했다는 표시를 남기고 큐에 삽입
// 4. 큐가 빌 때까지 해당 과정을 반복

#include <iostream>
#include <queue>
using namespace std;


#define X first
#define Y second

int board[501][501];
bool visit[501][501];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; // n은 행, m은 열을 의미 (n -> x, m -> y)
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	int maxSize = 0;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visit[i][j] != true && board[i][j] == 1)
			{
				int curSize = 0;

				queue<pair<int, int>> q;
				q.push({ i, j });
				visit[i][j] = true;

				while (!q.empty())
				{
					auto cur = q.front(); q.pop();
					curSize++;
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						// 범위 밖이라면 아무것도 하지 않음
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						
						// 이미 방문했거나, 그림의 영역이 아닌 경우 아무것도 하지 않음
						if (visit[nx][ny] == true || board[nx][ny] != 1) continue;
						visit[nx][ny] = true;
						q.push({ nx, ny });
					}
				}

				if (maxSize < curSize) maxSize = curSize;
				count++;
			}
		}
	}

	cout << count << "\n";
	cout << maxSize << "\n";
	return 0;
}