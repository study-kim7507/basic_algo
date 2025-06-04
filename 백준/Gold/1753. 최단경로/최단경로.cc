// 주어진 시작점에서 다른 모든 정점으로의 최단 경로

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int v, e, k;
vector<pair<int, int>> adj[20001];
const int INF = 0x3f3f3f3f;
int d[20001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> v >> e >> k;
	fill(d, d + v + 1, INF);
	d[k] = 0;

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}

	// {거리, 정점}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, k });
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

	for (int i = 1; i <= v; i++)
	{
		if (d[i] == INF) cout << "INF" << "\n";
		else cout << d[i] << "\n";
	}

	return 0;
}