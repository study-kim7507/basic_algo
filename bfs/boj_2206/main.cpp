// (0, 0) -> (N-1, M-1)

#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int board[1001][1001];
int visit[1001][1001][2];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M; // board[N][M]

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			board[i][j] = int(str[j]-'0');
		}
	}

	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, 0});
	visit[0][0][0] = 1;

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = get<0>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visit[nx][ny][get<2>(cur)] > 0) continue;
			if (get<2>(cur) == 0)
			{
				// 벽을 부시지 않고 온 경우
				// 다음으로 나아가야 할 칸이 벽이 아닌 경우
				if (board[nx][ny] == 0)
				{
					visit[nx][ny][0] = visit[get<0>(cur)][get<1>(cur)][0] + 1;
					q.push({ nx, ny, 0 });
				}
				// 다음으로 나아가야 할 칸이 벽인 경우
				else if (board[nx][ny] == 1)
				{
					visit[nx][ny][1] = visit[get<0>(cur)][get<1>(cur)][0] + 1;
					q.push({ nx, ny, 1 });
				}
				
			}
			else if (get<2>(cur) == 1)
			{
				// 벽을 부시고 온 경우
				// 다음으로 나아가야 할 칸이 벽이 아닌 경우
				if (board[nx][ny] == 0)
				{
					visit[nx][ny][1] = visit[get<0>(cur)][get<1>(cur)][1] + 1;
					q.push({ nx, ny, 1 });
				}
			}
		}
	}

	if (visit[N - 1][M - 1][0] != 0 && visit[N - 1][M - 1][1] != 0)
	{
		cout << min({ visit[N - 1][M - 1][0], visit[N - 1][M - 1][1] }) << "\n";
	}
	else if (visit[N - 1][M - 1][0] == 0 && visit[N - 1][M - 1][1] == 0)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << max({ visit[N - 1][M - 1][0], visit[N - 1][M - 1][1] }) << "\n";
	}
	return 0;
}