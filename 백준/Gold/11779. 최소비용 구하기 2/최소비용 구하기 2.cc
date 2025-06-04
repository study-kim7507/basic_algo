// BOJ_11779. 최소비용 구하기 2
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f

int n, m, st, en;
vector<pair<int, int>> adjs[1001];
int dist[1001];
int pre[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adjs[u].push_back({ w, v });
	}

	fill(dist, dist + 1001, INF);

	cin >> st >> en;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, st });
	dist[st] = 0;
	
	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if (dist[cur.second] != cur.first) continue;
		for (auto nxt : adjs[cur.second])
		{
			if (dist[nxt.second] <= dist[cur.second] + nxt.first) continue;

			dist[nxt.second] = dist[cur.second] + nxt.first;
			pre[nxt.second] = cur.second;
			pq.push({ dist[nxt.second], nxt.second });
		}
	}

	std::cout << dist[en] << "\n";
	vector<int> routes;
	
	int cur = en;
	while (cur != st)
	{
		routes.push_back(cur);
		cur = pre[cur];
	}
	routes.push_back(cur);

	reverse(routes.begin(), routes.end());
	std::cout << routes.size() << "\n";
	for (auto e : routes)
		std::cout << e << " ";
	
	return 0;
}