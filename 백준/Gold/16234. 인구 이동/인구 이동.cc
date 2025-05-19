// BOJ_16234. 인구 이동
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, l, r;
	cin >> n >> l >> r;

	vector<vector<int>> board(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	int day = 0;
	for (day = 0; ; day++)
	{
		bool can = false;	// 연합이 존재하는지
		vector<vector<bool>> vis(n, vector<bool>(n, false));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (vis[i][j]) continue;
				
				vector<pair<int, int>> uni; // 연합
				int cnt = 0;				// 연합의 총 인구 수

				queue<pair<int, int>> q;
				q.push({ i, j });
				vis[i][j] = true;
				
				while (!q.empty())
				{
					auto cur = q.front(); q.pop();
					uni.push_back(cur);
					cnt += board[cur.X][cur.Y];

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (vis[nx][ny]) continue;
						if (!(abs(board[cur.X][cur.Y] - board[nx][ny]) >= l && abs(board[cur.X][cur.Y] - board[nx][ny]) <= r)) continue;

						vis[nx][ny] = true;
						q.push({ nx, ny });
					}
				}

				if (uni.size() > 1)
				{
					can = true;
					int num = cnt / (int)uni.size();
					for (auto e : uni)
						board[e.X][e.Y] = num;
				}
			}
		}

		if (!can) break;
	}

	std::cout << day << "\n";
	return 0;
}