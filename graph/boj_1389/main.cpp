#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[101];
int dist[101];	
int kebin[101];					

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


	for (int i = 1; i <= n; i++)
	{
		sort(adj[i].begin(), adj[i].end());
		adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
	}
		
	for (int i = 1; i <= n; i++)
	{
		int curKebin = 0;
		fill(dist + 1, dist + n + 1, -1);

		queue<int> q;
		q.push(i);
		dist[i] = 0;
		while (!q.empty())
		{
			auto cur = q.front(); q.pop();
			for (auto nxt : adj[cur])
			{
				if (dist[nxt] != -1) continue;
				dist[nxt] = dist[cur] + 1;
				curKebin += dist[nxt];
				q.push(nxt);
			}
		}

		kebin[i] = curKebin;
	}

	int min = *min_element(kebin + 1, kebin + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (kebin[i] == min)
		{
			cout << i << "\n";
			return 0;
		}
	}
	return 0;
}