#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
int board[101][101];
const int INF = 987654321;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
		fill(board[i] + 1, board[i] + n + 1, INF);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int num;
			cin >> num;
			if (num == 1)
				board[i][j] = 1;

		}
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (board[i][k] + board[k][j] < board[i][j])
					board[i][j] = board[i][k] + board[k][j];
			}
		}
	}
	

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (board[i][j] == INF) cout << 0 << " ";
			else cout << 1 << " ";
		}
		cout << "\n";
	}
	return 0;
}