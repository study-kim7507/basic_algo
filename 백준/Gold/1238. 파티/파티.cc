// BOJ 1238. 파티
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int n, m, x;
int cost[1001];

void dijkstra(vector<pair<int, int>> (&e)[1001])
{
	int dist[1001];
	fill(dist, dist + 1001, INT_MAX);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[x] = 0;
	pq.push({ dist[x], x });
	
	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if (dist[cur.second] != cur.first) continue;	
		for (auto nxt : e[cur.second])
		{
			if (dist[nxt.first] <= cur.first + nxt.second) continue;
			dist[nxt.first] = cur.first + nxt.second;
			pq.push({ dist[nxt.first], nxt.first });
		}
	}

	for (int i = 1; i <= n; i++)
		cost[i] += dist[i];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<pair<int, int>> edges[1001];
	vector<pair<int, int>> revEdges[1001];

	cin >> n >> m >> x;
	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		edges[u].push_back({ v, c });
		revEdges[v].push_back({ u, c });
	}

	dijkstra(edges);	// x 마을에서 각 마을까지의 최단거리 계산
	dijkstra(revEdges); // 각 마을에서 x 마을까지의 최단거리 계산

	cout << *max_element(cost + 1, cost + n + 1) << "\n";
	return 0;
}