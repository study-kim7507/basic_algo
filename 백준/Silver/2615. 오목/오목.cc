// 2615. 오목
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[8] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };

int board[20][20];

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second < b.second) return true;
	if (a.second == b.second) return a.first <= b.first;
	return false;
}

pair<int, int> check(int x, int y)
{
	int cur = board[x][y];
	for (int dir = 0; dir < 8; dir++)
	{
		int curX = x;
		int curY = y;
		int prevX = x - dx[dir];
		int prevY = y - dy[dir];

		bool can = true;
		vector<pair<int, int>> pos;
		pos.push_back({ curX, curY });

		for (int cnt = 1; cnt <= 5; cnt++)
		{
			curX = curX + dx[dir];
			curY = curY + dy[dir];
			if (curX >= 19 || curY >= 19)
			{
				can = false;
				break;
			}
			if (cnt != 5 && cur != board[curX][curY])
			{
				can = false;
				break;
			}
			if (cnt < 5) pos.push_back({ curX, curY });
			if (cnt == 5 && board[curX][curY] == cur)
			{
				can = false;
				break;
			}
		}
		if (can)
		{
			if ((prevX >= 0 && prevX < 19) && ((prevY >= 0) && (prevY < 19)) && 
				board[prevX][prevY] == cur) return {-1, -1};
			sort(pos.begin(), pos.end(), cmp);
			return pos[0];
		}
	}

	return { -1, -1 };
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++)
			cin >> board[i][j];

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (board[i][j] == 0) continue;
			pair<int, int> result = check(i, j);
			if (result != make_pair(-1, -1))
			{
				cout << board[i][j] << "\n";
				cout << result.first + 1 << " " << result.second + 1 << "\n";
				return 0;
			}
		}
	}

	cout << 0 << "\n";
	return 0;
}