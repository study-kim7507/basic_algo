// BOJ 11657. 타임머신
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 987654321

int n, m;
vector<tuple<int, int, int>> edges; // a에서 b로 가는데 걸리는 시간 c
long long dist[501];

bool bellmanford()
{
	dist[1] = 0;	// 시작 정점
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int from, to, cost;
			tie(from, to, cost) = edges[j];

			if (dist[from] == INF) continue;
			if (dist[to] > dist[from] + cost)
				dist[to] = dist[from] + cost;
		}
	}

	for (int j = 0; j < m; j++)
	{
		int from, to, cost;
		tie(from, to, cost) = edges[j];
		if (dist[from] == INF) continue;
		if (dist[to] > dist[from] + cost)
			return true;
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		edges.push_back(make_tuple(a, b, c));
	}

	fill(dist, dist + 501, INF);
	
	bool isNegativeCycle = bellmanford();
	if (isNegativeCycle) std::cout << -1 << "\n";
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (dist[i] == INF) std::cout << -1 << "\n";
			else std::cout << dist[i] << "\n";
		}
	}
	return 0;
}