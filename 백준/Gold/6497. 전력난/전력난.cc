// BOJ 6497. 전력난
#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int parent[200001];

int uf_find(int x)
{
	if (x != parent[x]) return parent[x] = uf_find(parent[x]);
	return x;
}

void uf_union(int x, int y)
{
	x = uf_find(x);
	y = uf_find(y);

	if (x <= y) parent[y] = x;
	else parent[x] = y;
}

void init(int m)
{
	for (int i = 0; i < m; i++)
		parent[i] = i;
}

int kruskal(vector<tuple<int, int, int>>& edges)
{
	sort(edges.begin(), edges.end());

	int ans = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		int x, y, z;
		tie(z, x, y) = edges[i];

		if (uf_find(x) != uf_find(y)) uf_union(x, y);
		else ans += z;
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int m, n;
	while (true)
	{
		cin >> m >> n;
		if (m == 0 && n == 0) break;

		vector<tuple<int, int, int>> edges;
		for (int i = 0; i < n; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;

			edges.push_back(make_tuple(z, x, y));
		}

		init(m);
		sort(edges.begin(), edges.end());
		
		std::cout << kruskal(edges) << "\n";
	}

	return 0;
}