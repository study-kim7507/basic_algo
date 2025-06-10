// BOJ_1987. 알파벳
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n, m;
char board[21][21];
vector<bool> vis(27, false);

int answer = 0;

void dfs(int x, int y, int cnt)
{
	answer = max(answer, cnt);

	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (!vis[board[nx][ny] - 'A'])
		{
			vis[board[nx][ny] - 'A'] = true;
			dfs(nx, ny, cnt + 1);
			vis[board[nx][ny] - 'A'] = false;
		}
	}
}

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
		{
			board[i][j] = row[j];
		}
	}


	vis[board[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	std::cout << answer << "\n";

	return 0;
}