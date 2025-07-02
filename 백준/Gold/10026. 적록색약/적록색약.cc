// BOJ_10026. 적록색약
#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n;
char board[101][101];

void bfs(bool isCB)
{
	bool vis[101][101];
	for (int i = 0; i < n; i++)
		fill(vis[i], vis[i] + n, false);

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vis[i][j]) continue;

			cnt++;
			queue<pair<int, int>> q;
			q.push({ i, j });
			vis[i][j] = true;

			while (!q.empty())
			{
				auto cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (vis[nx][ny]) continue;
					if (!isCB)
					{
						if (board[nx][ny] != board[cur.X][cur.Y]) 
							continue;
					}
					else
					{
						if (board[cur.X][cur.Y] == 'R' && board[nx][ny] == 'B') continue;
						if (board[cur.X][cur.Y] == 'G' && board[nx][ny] == 'B') continue;
						if (board[cur.X][cur.Y] == 'B' && board[nx][ny] != 'B') continue;
					}

					vis[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
		}
	}

	std::cout << cnt << " ";
	return;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string row;
		cin >> row;
		for (int j = 0; j < n; j++)
			board[i][j] = row[j];
	}

	bfs(false);
	bfs(true);
	
	return 0;
}