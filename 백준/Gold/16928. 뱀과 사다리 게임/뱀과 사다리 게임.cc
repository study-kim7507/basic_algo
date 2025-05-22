// BOJ_16928. 뱀과 사다리 게임
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;

vector<int> adj[101];
int vis[101];
int ladderOrSnake[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= 100; i++)
		for (int j = i + 1; j <= i + 6 && j <= 100; j++)
			adj[i].push_back(j);

	// 사다리
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		ladderOrSnake[x] = y;
	}

	// 뱀
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		ladderOrSnake[u] = v;
	}
	
	queue<int> q;
	q.push(1);
	vis[1] = 1;

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto nxt : adj[cur])
		{
			if (vis[nxt] != 0 && vis[nxt] <= vis[cur]) continue;

			if (ladderOrSnake[nxt] != 0)
			{
				vis[nxt] = vis[cur] + 1;
				if (vis[ladderOrSnake[nxt]] == 0 || (vis[ladderOrSnake[nxt]] != 0 && vis[ladderOrSnake[nxt]] > vis[cur]))
				{
					vis[ladderOrSnake[nxt]] = vis[nxt];
					q.push(ladderOrSnake[nxt]);
				}
			}
			else
			{
				vis[nxt] = vis[cur] + 1;
				q.push(nxt);
			}
		}
	}

	/*for (int i = 1; i <= 100; i++)
	{
		std::cout << vis[i] << " ";
	}
	std::cout << "\n";*/

	std::cout << vis[100] - 1 << "\n";
	return 0;
}