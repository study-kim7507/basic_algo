#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n;

// {비용, 정점1, 정점2}
vector<tuple<int, int, int>> edges;
int parent[1001];

int uf_find(int x)
{
	if (parent[x] != x)
		return parent[x] = uf_find(parent[x]);
	return x;
}

void uf_union(int x, int y)
{
	int a = uf_find(x);
	int b = uf_find(y);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int c;
			cin >> c;
			edges.push_back({ c, i, j });
		}
	}

	// 비용을 기준으로 오름차순 정렬
	sort(edges.begin(), edges.end());

	long long ans = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		int c, u, v;		// {비용, 정점1, 정점2}
		tie(c, u, v) = edges[i];
		if (uf_find(u) == uf_find(v)) continue;
		uf_union(u, v);
		ans += c;
	}

	cout << ans << "\n";

	return 0;
}