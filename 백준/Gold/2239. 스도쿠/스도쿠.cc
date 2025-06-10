// BOJ_2239. 스도쿠
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int board[9][9];
vector<pair<int, int>> emptyPos;

bool checkRow(int y, int x, int target)
{
	for (int i = 0; i < 9; i++)
	{
		if (board[y][i] == target) return true;
	}

	return false;
}

bool checkCol(int y, int x, int target)
{
	for (int i = 0; i < 9; i++)
	{
		if (board[i][x] == target) return true;
	}

	return false;
}

bool checkBox(int y, int x, int target)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[y / 3 * 3 + i][x / 3 * 3 + j] == target) return true;
		}
	}

	return false;
}

void dfs(int idx)
{
	if (idx >= emptyPos.size())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				std::cout << board[i][j];
			}
			std::cout << "\n";
		}

		exit(0);
	}

	int curY = emptyPos[idx].first;
	int curX = emptyPos[idx].second;

	for (int i = 1; i <= 9; i++)
	{
		if (checkRow(curY, curX, i) || checkCol(curY, curX, i) || checkBox(curY, curX, i)) continue;

		board[curY][curX] = i;
		dfs(idx + 1);
		board[curY][curX] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 9; i++)
	{
		string row;
		cin >> row;
		for (int j = 0; j < 9; j++)
		{
			board[i][j] = int(row[j] - '0');
			if (board[i][j] == 0) emptyPos.push_back({ i, j });
		}
	}

	dfs(0);
	return 0;
}