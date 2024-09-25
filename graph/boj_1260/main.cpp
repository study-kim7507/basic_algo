// DFS와 BFS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v;				// 정점의 개수, 간선의 개수, 시작 정점
vector<int> adj[1001];
bool vis[1001];

void bfs()
{
	queue<int> q;
	q.push(v);
	vis[v] = true;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		cout << cur << " ";
		for (auto nxt : adj[cur])
		{
			if (vis[nxt] == true) continue;
			vis[nxt] = true;
			q.push(nxt);
		}
	}
}


void dfs(int cur)
{
	cout << cur << " ";
	vis[cur] = true;
	for (auto nxt : adj[cur])
	{
		if (vis[nxt] == true) continue;
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
		int st, en;
		cin >> st >> en;
		adj[st].push_back(en);
		adj[en].push_back(st);
	}

	for (int i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end());
	
	dfs(v);
	fill(vis, vis + 1001, false);
	cout << "\n";
	bfs();

	return 0;
}