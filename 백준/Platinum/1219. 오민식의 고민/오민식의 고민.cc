// BOJ 1219. 오민식의 고민
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 987654321

int n, st, en, m;
vector<tuple<int, int, int>> edges;		// 교통수단, a에서 b로 가는데 드는 비용 c
vector<int> canEarn;					// 현재 도시에 도착할 경우 얻을 수 있는 돈
vector<long long> earned;

bool bfs(queue<int>& q, vector<bool>& visit)
{
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto edge : edges)
		{
			int u, v, c;
			tie(u, v, c) = edge;

			if (cur != u) continue;
			if (visit[v]) continue;

			visit[v] = true;
			q.push(v);
		}
	}

	return visit[en];
}

void bellmanford(bool& hasCycle, bool& canArrive)
{
	earned = vector<long long>(n + 1, -INF);
	earned[st] = canEarn[st];

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < edges.size(); j++)
		{
			int from, to, cost;
			tie(from, to, cost) = edges[j];

			if (earned[from] == -INF) continue;
			if (earned[to] < earned[from] + cost + canEarn[to])
				earned[to] = earned[from] + cost + canEarn[to];
		}
	}

	queue<int> q;
	vector<bool> visit(n + 1, false);
	for (int i = 0; i < edges.size(); i++)
	{
		int from, to, cost;
		tie(from, to, cost) = edges[i];

		if (earned[from] == -INF) continue;
		if (earned[to] < earned[from] + cost + canEarn[to])
		{
			hasCycle = true;
			q.push(to);
			visit[to] = true;
		}
	}

	canArrive = bfs(q, visit);
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

	for (int i = 0; i < n; i++)
	{
		int earn;
		cin >> earn;
		canEarn.push_back(earn);
	}

	bool hasCycle = false;
	bool canArrive = false;
	bellmanford(hasCycle, canArrive);

	if (hasCycle && canArrive) std::cout << "Gee" << "\n";
	else
	{
		if (earned[en] == -INF) std::cout << "gg" << "\n";
		else std::cout << earned[en] << "\n";
	}
	return 0;
}