// BOJ_1504. 특정한 최단 경로
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f

int n, e, v1, v2;
vector<pair<int, int>> adjs[801];

int dijkstra(int st, int en)
{
	int dist[801];
	fill(dist, dist + 801, INF);

	dist[st] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, st });

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if (dist[cur.second] != cur.first) continue;
		for (auto nxt : adjs[cur.second])
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

	// 간선 입력
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adjs[a].push_back({ c, b });
		adjs[b].push_back({ c, a });
	}

	// 반드시 지나야 하는 두 정점 입력
	cin >> v1 >> v2;


	int answer = 0;

	// 1 -> v1 -> v2 -> n
	int OneToV1 = dijkstra(1, v1);
	int V1ToV2 = dijkstra(v1, v2);
	int V2ToN = dijkstra(v2, n);

	if (OneToV1 == INF || V1ToV2 == INF || V2ToN == INF) answer = INF;
	else answer = OneToV1 + V1ToV2 + V2ToN;

	// 1 -> v2 -> v1 -> n
	int OneToV2 = dijkstra(1, v2);
	int V2ToV1 = dijkstra(v2, v1);
	int V1ToN = dijkstra(v1, n);

	if (!(OneToV2 == INF || V2ToV1 == INF || V1ToN == INF)) answer = min(answer, OneToV2 + V2ToV1 + V1ToN);

	if (answer >= INF) std::cout << -1 << "\n";
	else std::cout << answer << "\n";

	return 0;
}