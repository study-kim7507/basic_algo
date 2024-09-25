#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, ans;
vector<int> adj[101];
bool vis[101];

void bfs()
{
	queue<int> q;
	q.push(1);
	vis[1] = true;

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		ans++;
		for (auto nxt : adj[cur])
		{
			if (vis[nxt] == true) continue;
			vis[nxt] = true;
			q.push(nxt);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs();
	cout << ans - 1 << "\n";
	return 0;
}