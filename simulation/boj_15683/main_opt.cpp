// 각 카메라가 가질 수 있는 방향의 경우의 수는 최대 4가지 -> 4진법을 이용

#include <iostream>
#include <vector>
using namespace std;

#define X first
#define Y second

int n, m; // x, y
int board[10][10];
int board2[10][10];

// 시계 방향으로 90도 돌도록
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<pair<int, int>> cctv;


int ans = 987654321;

void upd(int x, int y, int dir)
{
	dir %= 4;
	while (1)
	{
		x += dx[dir];
		y += dy[dir];

		if (x < 0 || x >= n || y < 0 || y >= m) break;
		if (board[x][y] == 6) break;
		if (board[x][y] >= 1 && board[x][y] <= 5) continue;
		board[x][y] = -1;			// 카메라가 영향을 미치는 영역은 -1로 표기
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			board2[i][j] = board[i][j];
			if (board[i][j] >= 1 && board[i][j] <= 5)
				cctv.push_back({ i, j });
		}
	}

	for (int j = 0; j < (1 << cctv.size() * 2); j++)
	{
		int tmp = j;
		for (int i = 0; i < cctv.size(); i++)
		{
			int dir = tmp % 4;

			int x = cctv[i].X;
			int y = cctv[i].Y;
			if (board[x][y] == 1)
			{
				upd(x, y, dir);
			}
			else if (board[x][y] == 2)
			{
				upd(x, y, dir);
				upd(x, y, dir + 2);
			}
			else if (board[x][y] == 3)
			{
				upd(x, y, dir);
				upd(x, y, dir + 1);
			}
			else if (board[x][y] == 4)
			{
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 3);
			}
			else if (board[x][y] == 5)
			{
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 2);
				upd(x, y, dir + 3);
			}
			tmp /= 4;
		}

		int tmpResult = 0;
		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < m; b++)
			{
				if (board[a][b] == 0) tmpResult++;
				board[a][b] = board2[a][b];
			}
		}
		if (ans > tmpResult) ans = tmpResult;
	}

	cout << ans << "\n";
	return 0;
}