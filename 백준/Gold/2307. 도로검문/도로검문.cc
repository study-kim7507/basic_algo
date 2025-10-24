// BOJ 2307. 도로검문
#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> edges;

// 경로 복원용
vector<int> path;

// 결과
int ans = 0;

int dijkstra(int blockedA, int blockedB, int originShortestDistance)
{
	vector<int> dist(n + 1, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[1] = 0;
	path[1] = -1;
	pq.push({ dist[1], 1 });

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if (dist[cur.second] != cur.first) continue;

		for (auto nxt : edges[cur.second])
		{
			if (dist[nxt.second] <= nxt.first + dist[cur.second]) continue;
			
			// 양방향 도로 차단
			if (nxt.second == blockedA && cur.second == blockedB) continue;	
			if (nxt.second == blockedB && cur.second == blockedA) continue;

			dist[nxt.second] = nxt.first + dist[cur.second];
			pq.push({ dist[nxt.second], nxt.second });
		}
	}

	if (dist[n] == INT_MAX) return -1;
	return dist[n] - originShortestDistance;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	edges = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>());
	path = vector<int>(n + 1, INT_MAX);

	for (int i = 0; i < m; i++)
	{
		int a, b, t;
		cin >> a >> b >> t;

		edges[a].push_back({ t, b });
		edges[b].push_back({ t, a });
	}

	vector<int> dist(n + 1, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[1] = 0;
	path[1] = -1;
	pq.push({ dist[1], 1 });

	
	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if (dist[cur.second] != cur.first) continue;

		for (auto nxt : edges[cur.second])
		{
			if (dist[nxt.second] <= nxt.first + dist[cur.second]) continue;

			dist[nxt.second] = nxt.first + dist[cur.second];
			path[nxt.second] = cur.second;
			pq.push({ dist[nxt.second], nxt.second });
		}
	}
	
	int cur = n;
	while (true)
	{
		int nxt = path[cur];
		if (nxt == -1) break;

		int curResult = dijkstra(cur, nxt, dist[n]);
		if (curResult == -1)
		{
			std::cout << -1 << "\n";
			return 0;
		}
		else
		{
			// std::cout << curResult << ": " << cur << " " << nxt << "\n";
			ans = max(ans, curResult);
		}
		cur = nxt;
	}

	std::cout << ans << "\n";
	return 0;
}