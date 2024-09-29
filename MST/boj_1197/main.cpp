#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct edge
{
	int u, v;
	int cost;
};

struct cmp
{
	bool operator() (const edge& a, const edge& b)
	{
		return a.cost >= b.cost;
	}
};

int v, e;
priority_queue<edge, vector<edge>, cmp> edges;
int parent[10001];
vector<edge> mst;

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

	cin >> v >> e;
	for (int i = 1; i <= v; i++)
		parent[i] = i;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push({ a, b, c });
	}

	while (mst.size() != v - 1)
	{
		auto cur = edges.top(); edges.pop();
		if (uf_find(cur.u) == uf_find(cur.v)) continue;
		uf_union(cur.u, cur.v);
		mst.push_back(cur);
	}

	int sum = 0;
	for (const auto& e : mst)
		sum += e.cost;
	cout << sum << "\n";

	return 0;
}