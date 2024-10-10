#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, s, e;
vector<int> adj[100001];
int vis[100001];				
int parent[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s >> e;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	fill(vis, vis + n + 1, -1);

	queue<int> q;
	q.push(s);
	vis[s] = 0;

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto nxt : adj[cur])
		{
			if (vis[nxt] != -1) continue;
			vis[nxt] = vis[cur] + 1;
			q.push(nxt);
			parent[nxt] = cur;
		}
	}
	// vis[e]가 홀이면 F, vis[e]가 짝이면 S

	// 부모가 F인데 자식이 하나 밖에 없으면 F가 이김
	// 부모가 F인데 자식이 여러 명이면 S가 이김
	// 부모가 S인데 자식이 하나 밖에 없으면 F가 이김
	// 부모가 S인데 자식이 여러 명이면 F가 이김
	if (vis[parent[e]] % 2 == 0 || adj[parent[e]].size() - 1 == 1)
		cout << "First" << "\n";
	else
		cout << "Second" << "\n";
		
	

	return 0;
}
