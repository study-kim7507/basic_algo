// BOJ_18405. 경쟁적 전염
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

const int dx[4] = { -1, 0 , 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n, k;
int s, x, y;
int board[201][201];

// 바이러스가 존재하는 좌표 저장
queue<pair<int, int>> virus[1001];	

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] != 0) 
				virus[board[i][j]].push({ i, j });
		}
	}
	
	cin >> s >> x >> y;
	
	for (int t = 0; t < s; t++)
	{
		for (int i = 1; i <= k; i++)
		{
			queue<pair<int, int>> q;
			while (!virus[i].empty())
			{
				q.push(virus[i].front());
				virus[i].pop();
			}

			while (!q.empty())
			{
				auto cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] != 0) continue;

					board[nx][ny] = i;
					virus[i].push({ nx, ny });
				}
			}
		}
	}
	
	std::cout << board[x - 1][y - 1] << "\n";

	return 0;
}