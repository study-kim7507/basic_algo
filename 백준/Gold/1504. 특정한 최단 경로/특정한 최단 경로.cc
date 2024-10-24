// 특정한 최단 경로
// 1 -> v1 -> v2 -> n
// 1 -> v2 -> v1 -> n
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, e;

// adj[u] = {c, v}
// u에서 v로 가는 비용 c
vector<pair<int, int>> adj[1000];

const int INF = 0x3f3f3f3f;
long long dijkstra(int st, int en)
{
	long long dist[801];
	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[st] = 0;
	pq.push({ dist[st], st});
	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if (dist[cur.second] < cur.first) continue;
		for (auto nxt : adj[cur.second])
		{
			if (dist[nxt.second] <= dist[cur.second] + nxt.first) continue;
			dist[nxt.second] = dist[cur.second] + nxt.first;
			pq.push({ dist[nxt.second], nxt.second });
		}
	}

	return dist[en];
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> e;
	
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}

	int v1, v2;
	cin >> v1 >> v2;

	long long route1 = (long long)(dijkstra(1, v1)) + (long long)(dijkstra(v1, v2)) + (long long)(dijkstra(v2, n));
	long long route2 = (long long)(dijkstra(1, v2)) + (long long)(dijkstra(v2, v1)) + (long long)(dijkstra(v1, n));
	long long ans = min(route1, route2);

	if (ans >= INF) cout << -1 << "\n";
	else cout << ans << "\n";
	return 0;
}