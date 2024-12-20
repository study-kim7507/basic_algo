// 2206. 벽 부수고 이동하기

#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int board[1001][1001];
int vis[1001][1001][2];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < m; j++)
		{
			board[i][j] = static_cast<int>(input[j] - '0');
		}
	}

	queue<tuple<int, int, int>> q;
	vis[0][0][0] = 1;
	q.push({ 0, 0, 0 });

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		bool isBroken = static_cast<bool>(get<2>(cur));
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = get<0>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (vis[nx][ny][get<2>(cur)] != 0) continue;

			// 벽을 부수고 온 경우
			if (isBroken)
			{
				// 이미 벽을 부수고 왔기 때문에 추가적인 벽을 부술 수 없음
				if (board[nx][ny] == 1) continue;
			
				vis[nx][ny][1] = vis[get<0>(cur)][get<1>(cur)][1] + 1;
				q.push({ nx, ny, 1 });
			}

			// 벽을 부수지 않고 온 경우
			else
			{
				// 벽을 부수지 않고 왔는데, 벽을 만난 경우
				if (board[nx][ny] == 1)
				{
					// 현재 만난 벽을 부술 경우
					vis[nx][ny][1] = vis[get<0>(cur)][get<1>(cur)][0] + 1;
					q.push({ nx, ny, 1 });
				}
				else
				{

					vis[nx][ny][0] = vis[get<0>(cur)][get<1>(cur)][0] + 1;
					q.push({ nx, ny, 0 });
				}

			}
		}
	}

	int result = 987654321;

	if (vis[n - 1][m - 1][0] != 0) result = min(result, vis[n - 1][m - 1][0]);
	if (vis[n - 1][m - 1][1] != 0) result = min(result, vis[n - 1][m - 1][1]);
	
	if (result == 987654321) cout << -1 << "\n";
	else cout << result << "\n";

	return 0;
}