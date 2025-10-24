// BOJ 11404. 플로이드
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

#define INF 987654321

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	// 초기화
	int board[101][101];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) board[i][j] = 0;
			else board[i][j] = INF;
		}
	}
		

	// 입력
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		board[a][b] = min(board[a][b], c);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				board[j][k] = min(board[j][k], board[j][i] + board[i][k]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (board[i][j] == INF) std::cout << 0 << " ";
			else std::cout << board[i][j] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}