// 다익스트라 풀이
// 시작 정점에서 모든 정점까지의 최단거리
// N번의 다익스트라, 시작 마을에서 파티가 열리는 마을까지의 거리 + 파티가 열리는 마을에서 시작 마을까지의 거리가 최대가 되는 경우를 찾으면 된다

#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int n, m, x;

// {거리, 정점}
vector<pair<int, int>> adj[1001];
const int INF = 0x3f3f3f3f;
int d[1001];

int dijkstra(int st)
{
	fill(d, d + n + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	d[st] = 0;
	pq.push({ d[st], st }); // {거리, 정점}
	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue;
		for (auto nxt : adj[cur.second])
		{
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({ d[nxt.second], nxt.second });
		}
	}

	return d[x];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> x;
	for (int i = 0; i < m; i++)
	{
		int u, v, t;
		cin >> u >> v >> t;
		adj[u].push_back({ t, v });
	}

	// 각 마을에서 파티가 열리는 마을까지 가는데 드는 거리
	int result[1001];
	for (int i = 1; i <= n; i++)
		result[i] = dijkstra(i);
	
	// 파티가 열리는 마을에서 각 마을로 되돌아가는 거리를 합산하며 최대값을 찾음
	dijkstra(x);
	int m = numeric_limits<int>::min();
	for (int i = 1; i <= n; i++)
	{
		result[i] += d[i];
		m = max(m, result[i]);
	}
		
	cout << m;
	return 0;
}