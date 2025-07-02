// BOJ_2206. 벽 부수고 이동하기
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n, m;
int board[1001][1001];
int dist[1001][1001][2];	// 0 : 벽을 안부수고 이동, 1 : 벽을 부수고 이동

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string row;
		cin >> row;
		for (int j = 0; j < m; j++)
			board[i][j] = (int)(row[j] - '0');
	}

	queue<pair<bool, pair<int, int>>> q;
	q.push({ false, {0, 0} });
	dist[0][0][0] = 1;

	while (!q.empty())
	{
		bool isBroken = q.front().first;
		auto curPos = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = curPos.X + dx[dir];
			int ny = curPos.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;	// 범위 밖
			if (isBroken && dist[nx][ny][1]) continue;
			if (!isBroken && dist[nx][ny][0]) continue;

			if (board[nx][ny] == 0)
			{
				if (isBroken)
				{
					dist[nx][ny][1] = dist[curPos.X][curPos.Y][1] + 1;
					q.push({ true, {nx, ny} });
				}
				else
				{
					dist[nx][ny][0] = dist[curPos.X][curPos.Y][0] + 1;
					q.push({ false, {nx, ny} });
				}
			}
			else if (board[nx][ny] == 1)
			{
				if (isBroken) continue;	// 이미 부수고 왔기에, 더 이상 부술 수 없음
				else dist[nx][ny][1] = dist[curPos.X][curPos.Y][0] + 1;
				q.push({ true, {nx, ny} });
			}
		}
	}

	int unbrokenDist = dist[n - 1][m - 1][0];
	int brokenDist = dist[n - 1][m - 1][1];

	if (unbrokenDist == 0 && brokenDist == 0) std::cout << -1 << "\n";
	else if (unbrokenDist == 0) std::cout << brokenDist << "\n";
	else if (brokenDist == 0) std::cout << unbrokenDist << "\n";
	else std::cout << min(unbrokenDist, brokenDist) << "\n";
	return 0;
}