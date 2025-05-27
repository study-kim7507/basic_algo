// BOJ_2636. 치즈
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define X first
#define Y second

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> board(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	int i = 0;
	int prevMeltCnt = 0;
	for (i = 0; ; i++)
	{
		vector<vector<bool>> vis(n, vector<bool>(m, false));
		vector<vector<int>> melt = board;

		int curMeltCnt = 0;

		queue<pair<int, int>> q;
		q.push({ 0, 0 });
		vis[0][0] = true;

		while (!q.empty())
		{
			auto cur = q.front(); q.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (vis[nx][ny]) continue;

				if (board[nx][ny] == 1)
				{
					melt[nx][ny] = 0;
					curMeltCnt++;
					vis[nx][ny] = true;
				}
				else
				{
					vis[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
			
		}

		board = melt;

		if (curMeltCnt == 0) break;
		else prevMeltCnt = curMeltCnt;
	}

	std::cout << i << "\n" << prevMeltCnt << "\n";
	return 0;
}