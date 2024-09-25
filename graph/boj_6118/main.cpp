#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> adj[50001];
int dist[50001];
int result[50001];

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

	fill(dist, dist + n + 1, -1);
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto nxt : adj[cur])
		{
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}

	int r1 = -1;
	int r2 = *max_element(dist + 1, dist + n + 1);
	int r3 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (r1 == -1 && dist[i] == r2) r1 = i;
		if (dist[i] == r2) r3++;
	}

	cout << r1 << " " << r2 << " " << r3 << "\n";
	return 0;
}