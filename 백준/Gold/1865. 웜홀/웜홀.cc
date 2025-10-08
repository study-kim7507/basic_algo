// BOJ 1865. 웜홀
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

#define INF 987654321

bool bellmanford(int n, vector<tuple<int ,int, int>>& edges)
{
	vector<int> dist(n + 1, INF);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < edges.size(); j++)
		{
			int from, to, cost;
			tie(from, to, cost) = edges[j];

			if (dist[to] > dist[from] + cost)
			{
				dist[to] = dist[from] + cost;
				if (i == n) return true;
			}
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m, w;
		cin >> n >> m >> w;
		
		vector<tuple<int, int, int>> edges;
		for (int i = 0; i < m; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			edges.push_back(make_tuple(s, e, t));
			edges.push_back(make_tuple(e, s, t));
		}

		for (int i = 0; i < w; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			edges.push_back(make_tuple(s, e, -t));
		}

		bool hasNegativeCycle = bellmanford(n, edges);
		if (hasNegativeCycle) std::cout << "YES" << "\n";
		else std::cout << "NO" << "\n";
	}

	return 0;
}