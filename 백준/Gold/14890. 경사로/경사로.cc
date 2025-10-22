// BOJ 14890. 경사로
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, l;

vector<vector<int>> board(101, vector<int>(101));
vector<vector<int>> board_t(101, vector<int>(101));

int ans = 0;

void solve(vector<vector<int>>& targetBoard)
{
	bool slope[101][101];
	memset(slope, false, sizeof(slope));

	for (int i = 0; i < n; i++)
	{
		bool can = true;
		for (int j = 0; j < n - 1; j++)
		{
			if (abs(targetBoard[i][j] - targetBoard[i][j + 1]) > 1)
			{
				can = false;
				break;
			}

			// 내려가는 경사로
			if (targetBoard[i][j] - targetBoard[i][j + 1] == 1)
			{
				for (int k = j + 1; k <= j + l; k++)
				{
					if (k >= n || targetBoard[i][k] != targetBoard[i][j] - 1)
					{
						can = false;
						break;
					}
				}
				if (can)
				{
					for (int k = j + 1; k <= j + l; k++)
						slope[i][k] = true;
				}
			}

			// 올라가는 경사로
			if (targetBoard[i][j] - targetBoard[i][j + 1] == -1)
			{
				for (int k = j; k >= j - l + 1; k--)
				{
					if (k < 0 || targetBoard[i][k] != targetBoard[i][j] || slope[i][k])
					{
						can = false;
						break;
					}
				}
			}
		}

		if (can)
			ans++;
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> l;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			board_t[j][i] = board[i][j];
		}
	}
		
	solve(board);
	solve(board_t);

	std::cout << ans << "\n";
	return 0;
}