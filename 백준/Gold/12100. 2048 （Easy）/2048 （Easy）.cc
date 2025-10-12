// BOJ 12100. 2048 (easy)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int board[21][21];

bool isAlreadyMerged[21][21];

void init()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			isAlreadyMerged[i][j] = false;
}

void up()
{
	init();

	// 위 방향, 맨 윗줄에 있던 블록은 변동 없음
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = i - 1; k >= 0; k--)
			{
				if (isAlreadyMerged[k][j] || (board[k][j] != 0 && (board[k][j] != board[k + 1][j]))) continue;
				if ((!isAlreadyMerged[k][j] && !isAlreadyMerged[k + 1][j]) && (board[k][j] != 0 && (board[k][j] == board[k + 1][j])))
				{
					isAlreadyMerged[k][j] = true;
					board[k][j] += board[k + 1][j];
					board[k + 1][j] = 0;

				}
				if (!isAlreadyMerged[k][j] && (board[k][j] == 0 && board[k + 1][j]))
				{
					board[k][j] = board[k + 1][j];
					board[k + 1][j] = 0;
				}
			}
		}
	}
}

void down()
{
	init();

	// 아래 방향, 맨 아랫줄에 있던 블록은 변동 없음
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = i + 1; k < n; k++)
			{
				if (isAlreadyMerged[k][j] || (board[k][j] != 0 && (board[k][j] != board[k - 1][j]))) continue;
				if ((!isAlreadyMerged[k][j] && !isAlreadyMerged[k - 1][j]) && (board[k][j] != 0 && (board[k][j] == board[k - 1][j])))
				{
					isAlreadyMerged[k][j] = true;
					board[k][j] += board[k - 1][j];
					board[k - 1][j] = 0;

				}
				if (!isAlreadyMerged[k][j] && (board[k][j] == 0 && board[k - 1][j]))
				{
					board[k][j] = board[k - 1][j];
					board[k - 1][j] = 0;
				}
			}
		}
	}
}

void left()
{
	init();

	// 왼쪽 방향, 맨 왼쪽줄에 있던 블록은 변동 없음
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = i - 1; k >= 0; k--)
			{
				if (isAlreadyMerged[j][k] || (board[j][k] != 0 && (board[j][k] != board[j][k + 1]))) continue;
				if ((!isAlreadyMerged[j][k] && !isAlreadyMerged[j][k + 1]) && (board[j][k] != 0 && (board[j][k] == board[j][k + 1])))
				{
					isAlreadyMerged[j][k] = true;
					board[j][k] += board[j][k + 1];
					board[j][k + 1] = 0;
				}
				if (!isAlreadyMerged[j][k] && (board[j][k] == 0 && board[j][k + 1]))
				{
					board[j][k] = board[j][k + 1];
					board[j][k + 1] = 0;
				}
			}
		}
	}
}

void right()
{
	init();

	// 오른쪽 방향, 맨 오른쪽줄에 있던 블록은 변동 없음
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = i + 1; k < n; k++)
			{
				if (isAlreadyMerged[j][k] || (board[j][k] != 0 && (board[j][k] != board[j][k - 1]))) continue;
				if ((!isAlreadyMerged[j][k] && !isAlreadyMerged[j][k - 1]) && (board[j][k] != 0 && (board[j][k] == board[j][k - 1])))
				{
					isAlreadyMerged[j][k] = true;
					board[j][k] += board[j][k - 1];
					board[j][k - 1] = 0;
				}
				if (!isAlreadyMerged[j][k] && (board[j][k] == 0 && board[j][k - 1]))
				{
					board[j][k] = board[j][k - 1];
					board[j][k - 1] = 0;
				}
			}
		}
	}
}

void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << board[i][j] << " ";
		}
		std::cout << "\n";
	}
}


int ans = 0;

void dfs(int count)
{
	if (count == 5)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ans = max(ans, board[i][j]);

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int tempBoard[21][21];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				tempBoard[i][j] = board[i][j];

		if (i == 0)	up();
		else if (i == 1) down();
		else if (i == 2) left();	
		else if (i == 3) right();

		dfs(count + 1);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				board[i][j] = tempBoard[i][j];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	dfs(0);

	//up();
	//down();
	//left();
	//right();

	std::cout << ans << "\n";
	return 0;
}