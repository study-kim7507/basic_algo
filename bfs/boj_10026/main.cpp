#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

char board[101][101];
bool visit[101][101];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			board[i][j] = str[j];
		}
	}

	// 적록색약이 아닌 사람
	// 빨간색과 초록색 구분이 가능
	int no = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j]) continue;
			q.push({ i, j });
			visit[i][j] = true;
			no++;
			while (!q.empty())
			{
				auto cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if (visit[nx][ny] || board[nx][ny] != board[cur.X][cur.Y]) continue;
					q.push({ nx, ny });
					visit[nx][ny] = true;
				}
			}
		}
	}
	
	for (int i = 0; i < N; i++)
		fill(visit[i], visit[i] + N, false);

	// 적록색약인 사람
	// 빨간색과 초록색을 구분하지 못함
	int yes = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j]) continue;
			q.push({ i, j });
			visit[i][j] = true;
			yes++;
			while (!q.empty())
			{
				auto cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if (visit[nx][ny]) continue;
					if ((board[cur.X][cur.Y] == 'R' || board[cur.X][cur.Y] == 'G') && board[nx][ny] == 'B') continue;
					if (board[cur.X][cur.Y] == 'B' && (board[nx][ny] == 'R' || board[nx][ny] == 'G')) continue;
					q.push({ nx, ny });
					visit[nx][ny] = true;
				}
			}
		}
	}

	cout << no << " " << yes;
 	return 0;
}