#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m;

// {비용(1, 0) -> 오르막길인지, 정점1, 정점2}
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
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int cal()
{
	for (int i = 0; i <= n; i++)
		parent[i] = i;
	int cnt = 0;
	int ret = 0;

	for (int i = 0; i < edges.size(); i++)
	{
		int a, b, c;
		tie(c, a, b) = edges[i];
		if (uf_find(a) == uf_find(b)) continue;
		uf_union(a, b);
		ret += c;
		cnt++;
		if (cnt == n) return ret;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (c == 0) c = 1;
		else if (c == 1) c = 0;
		edges.push_back({ c, a, b });
		edges.push_back({ c, b, a });
	}

	// 최선의 경로
	sort(edges.begin(), edges.end());
	int ans1 = cal();

	// 최악의 경로
	sort(edges.rbegin(), edges.rend());
	int ans2 = cal();

	cout << ans2 * ans2 - ans1 * ans1<< "\n";
	return 0;
}