// 1707. 이분 그래프
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> edges[20001];
int group[20001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int v, e;
		cin >> v >> e;
		
		for (int i = 0; i < 20001; i++)
		{
			edges[i].clear();
			group[i] = 0;
		}

		for (int i = 0; i < e; i++)
		{
			int u, v;
			cin >> u >> v;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}

		bool canBipartite = true;
		for (int i = 1; i <= v; i++)
		{
			if (group[i] != 0) continue;

			queue<int> q;
			q.push(i);
			group[i] = 1;

			while (!q.empty())
			{
				auto cur = q.front(); q.pop();
				for (auto nxt : edges[cur])
				{

					if (group[nxt] == group[cur])
					{
						canBipartite = false;
						break;
					}
					if (group[nxt] != 0) continue;
					if (group[cur] == 1) group[nxt] = 2;
					else if (group[cur] == 2) group[nxt] = 1;
					q.push(nxt);
				}

				if (!canBipartite) break;
			}

			if (!canBipartite) break;
		}
		if (!canBipartite) cout << "NO" << "\n";
		else cout << "YES" << "\n";
	}

	return 0;
}
