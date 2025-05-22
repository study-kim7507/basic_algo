// BOJ_2589. 보물섬
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

char board[50][50];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
			board[i][j] = str[j];
	}
	
	vector<int> dists;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'W') continue;

			vector<vector<int>> vis(n, vector<int>(m, 0));

			queue<pair<int, int>> q;
			q.push({ i, j });
			vis[i][j] = 1;

			int maxDist = -1;
			while (!q.empty())
			{
				auto cur = q.front(); q.pop();
				maxDist = max(maxDist, vis[cur.X][cur.Y]);
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny]) continue;
					if (board[nx][ny] == 'W') continue;

					vis[nx][ny] = vis[cur.X][cur.Y] + 1;
					q.push({ nx, ny });
				}
			}

			dists.push_back(maxDist);
		}
	}

	std::cout << *max_element(dists.begin(), dists.end()) - 1 << "\n";
	return 0;
}