// BOJ 11780. 플로이드 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321


int board[101][101];
int nxt[101][101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	// 초기화
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			else board[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (c < board[a][b])
		{
			board[a][b] = c;
			nxt[a][b] = b;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (board[j][k] > board[j][i] + board[i][k])
				{
					board[j][k] = board[j][i] + board[i][k];
					nxt[j][k] = nxt[j][i];
				}
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

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (board[i][j] == 0 || board[i][j] == INF)
			{
				std::cout << 0 << "\n";
				continue;
			}

			vector<int> pathes;
			
			int st = i;
			pathes.push_back(st);
			while (st != j)
			{
				st = nxt[st][j];
				pathes.push_back(st);
			}

			std::cout << pathes.size() << " ";
			for (auto e : pathes)
				std::cout << e << " ";
			std::cout << "\n";

		}
	}

	return 0;
}