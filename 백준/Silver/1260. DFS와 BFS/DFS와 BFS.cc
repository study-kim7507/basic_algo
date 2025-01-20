// 1260. DFS와 BFS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v;
vector<int> edges[1001];
bool vis[1001];

void bfs(int st)
{
	queue<int> q;
	q.push(st);
	vis[st] = true;

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		cout << cur << " ";
		for (auto nxt : edges[cur])
		{
			if (vis[nxt] == true) continue;
			q.push(nxt);
			vis[nxt] = true;
		}
	}
}

void dfs(int cur)
{
	cout << cur << " ";
	vis[cur] = true;

	for (auto nxt : edges[cur])
	{
		if (vis[nxt]) continue;
		dfs(nxt);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	for (int i = 0; i <= n; i++)
		sort(edges[i].begin(), edges[i].end());


	fill(vis, vis + 1001, false);
	dfs(v);

	cout << "\n";

	fill(vis, vis + 1001, false);
	bfs(v);

	return 0;
}