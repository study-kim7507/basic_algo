#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int v, e;
int parent[100005];

// {비용, 정점1, 정점2}
tuple<int, int, int> edge[100005];

// Union-Find
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
	cin.tie(0);
	cout.tie(0);

	cin >> v >> e;
	for (int i = 1; i <= v; i++)
		parent[i] = i;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge[i] = tie(c, a, b);
	}

	// {비용, 정점1, 정점2} -> 비용을 기준으로 오름차순 정렬된다.
	sort(edge, edge + e);

	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < e; i++)
	{
		tuple<int, int, int> cur = edge[i];
		if (uf_find(get<1>(cur)) == uf_find(get<2>(cur))) continue;
		uf_union(get<1>(cur), get<2>(cur));
		ans += get<0>(cur);
		cnt++;
		if (cnt == v - 1) break;
	}

	cout << ans << "\n";
	return 0;
}