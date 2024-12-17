// 7576. 토마토

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int board[1001][1001];
int dist[1001][1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	bool isAlready = true;	// 이미 모두 익었는지 확인
	queue<pair<int, int>> q;

	// 토마토 상자 입력
	int n, m;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int input;
			cin >> input;
			board[i][j] = input;
			if (input == 1)
			{
				q.push({ i, j });
				dist[i][j] = 1;
			}
			if (input == 0) isAlready = false;
		}
	}

	// 이미 모든 토마토가 익어있는 경우 바로 종료
	if (isAlready)
	{
		cout << 0 << "\n";
		return 0;
	}

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] == -1 || dist[nx][ny] != 0) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx, ny });
		}
	}


	// 모든 토마토가 익을 수 있는지 확인 및 모든 토마토가 익는데 걸리는 최소 일수 계산
	int result = -1;
	bool isCan = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] != -1 && dist[i][j] == 0)
			{
				isCan = false;
			}
			result = max(result, dist[i][j] - 1);
		}
	}

	if (isCan) cout << result << "\n";
	else cout << -1 << "\n";

	return 0;
}