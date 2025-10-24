// BOJ 11657. 타임머신
#include <iostream>
#include <climits>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m;
vector<tuple<int, int, int>> edges;
vector<long long> dist;

bool bellmanford()
{
	dist = vector<long long>(n + 1, LLONG_MAX);
	dist[1] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < edges.size(); j++)
		{
			int from, to, cost;
			tie(from, to, cost) = edges[j];

			if (dist[from] != LLONG_MAX && dist[to] > dist[from] + cost)
			{
				dist[to] = dist[from] + cost;
				if (i == n - 1)	// n번째에도 갱신이 이루어진 경우 음의 사이클이 형성된 것임 -> 무한이 오래전으로 되돌릴 수 있음
					return true;
			}
		}
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

	if (bellmanford())
	{
		std::cout << -1 << "\n";
		return 0;
	}
	
	for (int i = 2; i <= n; i++)
	{
		if (dist[i] == LLONG_MAX) std::cout << -1 << "\n";
		else std::cout << dist[i] << "\n";
	}

	return 0;
}