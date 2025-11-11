// BOJ_1937. 욕심쟁이 판다
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n;
int board[501][501];
int dist[501][501];

int solve(int curX, int curY)
{
	if (dist[curX][curY] != 0)
		return dist[curX][curY];

	dist[curX][curY] = 1;
	for (int dir = 0; dir < 4; dir++)
	{
		int nx = curX + dx[dir];
		int ny = curY + dy[dir];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (board[nx][ny] <= board[curX][curY]) continue;

		dist[curX][curY] = max(dist[curX][curY], solve(nx, ny) + 1);
	}
	
	return dist[curX][curY];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans = max(ans, solve(i, j));
	std::cout << ans << "\n";
	return 0;
}