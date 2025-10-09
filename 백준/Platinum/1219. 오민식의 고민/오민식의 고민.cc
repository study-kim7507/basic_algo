// BOJ 1219. 오민식의 고민
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <tuple>
#include <algorithm>
using namespace std;

int st, en, n, m;
vector<tuple<int, int, int>> edges;
vector<int> money;

long long dist[51];

bool bfs(queue<int>& q, vector<bool>& visit)
{
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto edge : edges)
		{
			int from, to, cost;
			tie(from, to, cost) = edge;

			if (from != cur) continue;
			if (visit[to]) continue;

			visit[to] = true;
			q.push(to);
		}
	}

	return visit[en];
}

bool bellmanford()
{
	fill(dist, dist + 51, -LLONG_MAX);
	dist[st] = money[st];

	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 0; j < edges.size(); j++)
		{
			int from, to, cost;
			tie(from, to, cost) = edges[j];

			if (dist[from] == -LLONG_MAX) continue;

			if (dist[to] < dist[from] + cost)
				dist[to] = dist[from] + cost;
		}
	}

	queue<int> q;
	vector<bool> visit(n, false);

	for (int j = 0; j < edges.size(); j++)
	{
		int from, to, cost;
		tie(from, to, cost) = edges[j];

		if (dist[from] == -LLONG_MAX) continue;

		if (dist[to] < dist[from] + cost)
		{
			if (!visit[to])
			{
				visit[to] = true;
				q.push(to);
			}
		}
	}

	if (!q.empty())
		return bfs(q, visit);
	else
		return false;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> st >> en >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		edges.push_back(make_tuple(u, v, -c));
	}

	money = vector<int>(n, 0);
	for (int i = 0; i < n; i++)
		cin >> money[i];

	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		tie(u, v, c) = edges[i];
		
		c += money[v];
		edges[i] = make_tuple(u, v, c);
	}

	// 양의 무한 사이클이 있는 경우
	bool hasCycleToEn = bellmanford();

	if (hasCycleToEn)
	{
		std::cout << "Gee" << "\n";
	}
	else
	{
		// st에서 en까지 경로가 존재한다면 (dist가 갱신되었다면) 최대 이익 출력
		if (dist[en] != -LLONG_MAX) std::cout << dist[en] << "\n";
		// 경로가 없다면
		else std::cout << "gg" << "\n";
	}
	
	return 0;
}