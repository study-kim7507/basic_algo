#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int n, m;
vector<pair<int, int>> adj[1001]; 
int vis[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({ v, c });
		adj[v].push_back({ u, c });
	}

	while (m--)
	{
		fill(vis, vis + 1001, -1);
		int u, v;
		cin >> u >> v;
		
		queue<int> q;
		q.push(u);
		vis[u] = 0;
		while (!q.empty())
		{
			auto cur = q.front(); q.pop();
			for (auto nxt : adj[cur])
			{
				if (vis[nxt.first] != -1) continue;
				vis[nxt.first] = vis[cur] + nxt.second;
				q.push(nxt.first);
			}
		}
		cout << vis[v] << "\n";
	}

	return 0;
}