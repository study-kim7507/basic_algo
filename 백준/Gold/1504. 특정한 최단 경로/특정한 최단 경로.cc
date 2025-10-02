// BOJ 1504. 특정한 최단 거리
// 1 -> V1 -> V2 -> N
// 1 -> V2 -> V1 -> N
// 방향성이 없으므로 V1 -> V2 == V2 -> V1
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 987654321;

int n, e, v1, v2;
vector<pair<int, int>> edges[801];

int dijkstra(int st, int en)
{
	int dist[801];
	fill(dist, dist + 801, MAX);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[st] = 0;
	pq.push({ dist[st], st });
	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if (dist[cur.second] != cur.first) continue;
		for (auto nxt : edges[cur.second])
		{
			if (dist[nxt.first] <= nxt.second + cur.first) continue;
			dist[nxt.first] = nxt.second + cur.first;
			pq.push({ dist[nxt.first], nxt.first });
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
		int u, v, c;
		cin >> u >> v >> c;
		edges[u].push_back({ v, c });
		edges[v].push_back({ u, c });
	}
	cin >> v1 >> v2;

	int oneToV1, oneToV2, v1ToV2, v2ToV1, v1ToN, v2ToN;
	v1ToV2 = v2ToV1 = dijkstra(v1, v2);

	if (v1ToV2 == MAX || v2ToV1 == MAX)
	{
		std::cout << -1 << "\n";
		return 0;
	}

	oneToV1 = dijkstra(1, v1);
	oneToV2 = dijkstra(1, v2);
	v1ToN = dijkstra(v1, n);
	v2ToN = dijkstra(v2, n);

	int path1 = oneToV1 + v1ToV2 + v2ToN;
	int path2 = oneToV2 + v2ToV1 + v1ToN;

	if (path1 >= MAX && path2 >= MAX)
	{
		std::cout << -1 << "\n";
		return 0;
	}

	std::cout << min(path1, path2) << "\n";
	return 0;
}