// BOJ 2580. 스도쿠
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<vector<int>> board(9, vector<int>(9, 0));

unordered_set<int> rows[9];
unordered_set<int> cols[9];
unordered_set<int> boxes[9];

vector<pair<int, int>> emptyPos;
int emptyCount = 0;

void sudoku(int idx, vector<vector<int>>& curBoard)
{
	if (idx >= emptyCount)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				std::cout << curBoard[i][j] << " ";
			std::cout << "\n";
		}

		exit(0);
	}

	pair<int, int> curPos = emptyPos[idx];
	int r = curPos.first; 
	int c = curPos.second;
	int box = (r / 3) * 3 + (c / 3);

	for (int candi = 1; candi <= 9; candi++)
	{
		if (rows[r].find(candi) != rows[r].end() &&
			cols[c].find(candi) != cols[c].end() &&
			boxes[box].find(candi) != boxes[box].end())
		{
			curBoard[r][c] = candi;

			rows[r].erase(candi);
			cols[c].erase(candi);
			boxes[box].erase(candi);

			sudoku(idx + 1, curBoard);

			curBoard[r][c] = 0;

			rows[r].insert(candi);
			cols[c].insert(candi);
			boxes[box].insert(candi);
		}
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			rows[i].insert(j);
			cols[i].insert(j);
			boxes[i].insert(j);
		}
	}

	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			cin >> board[r][c];
			if (board[r][c] != 0)
			{
				rows[r].erase(board[r][c]);
				cols[c].erase(board[r][c]);
				boxes[(r / 3) * 3 + (c / 3)].erase(board[r][c]);
			}
			else
			{
				emptyPos.push_back({ r, c });
				emptyCount++;
			}
		}
	}
		
	sudoku(0, board);

	return 0;
}