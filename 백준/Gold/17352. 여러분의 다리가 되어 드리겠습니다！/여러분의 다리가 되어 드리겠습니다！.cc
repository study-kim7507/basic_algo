// BOJ_17352. 여러분의 다리가 되어 드리겠습니다.
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> parent;
vector<bool> vis;
vector<vector<int>> bridges;

int uf_find(int a)
{
	if (a != parent[a]) return parent[a] = uf_find(parent[a]);
	return a;
}

void uf_union(int a, int b)
{
	a = uf_find(a);
	b = uf_find(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	parent.assign(n + 1, 0);
	vis.assign(n + 1, false);
	bridges.assign(n + 1, vector<int>());

	for (int i = 1; i < parent.size(); i++)
		parent[i] = i;

	for (int i = 0; i < n - 2; i++)
	{
		int u, v;
		cin >> u >> v;
		bridges[u].push_back(v);
		bridges[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue;

		queue<int> q;
		q.push(i);
		vis[i] = true;
		while (!q.empty())
		{
			auto cur = q.front(); q.pop();
			for (auto nxt : bridges[cur])
			{
				if (vis[nxt]) continue;
				if (uf_find(cur) != uf_find(nxt))
				{
					uf_union(cur, nxt);
					vis[nxt] = true;
					q.push(nxt);
				}
			}
		}
	}

	parent.erase(unique(parent.begin(), parent.end()), parent.end());
	std::cout << parent[1] << " " << parent[2];
	return 0;
}